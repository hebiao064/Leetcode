### Overview

* [1 Two Sum](#1-two-sum)
* [2 Add Two Numbers](#2-add-two-numbers)
* [3 Longest Substring Without Repeating Characters](#3-longest-substring-without-repeating-characters)
* [4 Median of Two Sorted Arrays](#4-median-of-two-sorted-arrays)
* [5 Longest Palidromic Substring](#5-longest-palidromic-substring)
* [6 ZigZag Conversion](#6-zigzag-conversion)
* [7 Reverse Integer](#7-reverse-integer)
* [8 String to Integer (atoi)](#8-string-to-integer)
* [9 Palindrome Number](#9-palindrome-number)
* [11 Container With Most Water](#11-container-with-most-water)
* [12 Integer to Roman](#12-integer-to-roman)
* [13 Roman to Integer](#13-roman-to-integer)
* [14 Longest Common Prefix](#14-longest-common-prefix)
* [15 3 Sum](#15-3-sum)
* [16 3 Sum Closet](#16-3-sum-closet)
* [17 Letter Combinations of a Phone Number](#17-letter-combinations-of-a-phone-number)
* [18 4 Sum](#18-4-sum)
* [19 Remove Nth Node From End of List](#19-remove-nth-node-from-end-of-list)
* [20 Valid Parentheses](#20-valid-parentheses)
* [21 Merge Two Sorted Lists](#21-merge-two-sorted-lists)
* [22 Generate Parentheses](#22-generate-parentheses)
* [23 Merge k Sorted Lists](#23-merge-k-sorted-lists)
* [24 Swap Nodes in Pairs](#24-swap-nodes-in-pairs)
* [25 Reverse Nodes in kGroup](#25-reverse-nodes-in-kgroup)
* [26 Remove Duplicates from Sorted Array](#26-remove-duplicates-from-sorted-array)
* [27 Remove Element](#27-remove-element)
* [28 Implement strStr](#28-implement-strstr)
* [29 Divide Two Integers](#29-divide-two-integers)
* [30 Substring with Concatenation of All Words](#30-substring-with-concatenation-of-all-words)
* [31 Next Permutation](#31-next-permutation)
* [32 Longest Valid Parentheses](#32-longest-valid-parentheses)
* [33 Search in Rotated Sorted Array](#33-search-in-rotated-sorted-array)
* [34 Search for a Range](#34-search-for-a-range)
* [35 Search Insert Position](#35-search-insert-position)
* [36 Valid Sudoku](#36-valid-sudoku)
* [37 Sudoku Solver](#37-sudoku-solver)
* [38 Count and Say](#38-count-and-say)
* [39 Combination Sum](#39-combination-sum)
* [40 Combination Sum II](#40-combination-sum-ii)
* [41 First Missing Positive](#41-first-missing-positive)
* [42 Trapping Rain Water](#42-trapping-rain-water)
* [43 Multiply Strings](#43-multiply-strings)
* [44 Wildcard Matching](#44-wildcard-matching)
* [45 Jump Game II](#45-jump-game-ii)
* [46 Permutations](#46-permutations)
* [47 Permutations II](#47-permutations-ii)
* [48 Rotate Image](#48-rotate-image)
* [49 Group Anagrams](#49-group-anagrams)
* [50 Pow](#50-pow)

###Others
* [1 Fibonacci](#1-fibonacci)

<br>
### <a name="1-two-sum"></a>1 Two Sum

>Given an array of integers, find two numbers such that they add up to a specific target number.

>The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

>You may assume that each input would have exactly one solution.

>Input: numbers={2, 7, 11, 15}, target=9

>Output: index1=1, index2=2

**Idea**: Use HashMap to record the number one by one and check if it exist the target at the same time, only use one loop.

**Time Complexity** O(n)

**Space Complexity** O(n)

**Tags** HashMap

***C++ Code***
```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> result;
        for (int i = 0;i < nums.size();i++) {
            if (mp.count(target-nums[i])>0) {
                result.push_back(mp[target - nums[i]]);
                result.push_back(i + 1);
                return result;
            }
            mp[nums[i]] = i + 1;
        }
    }
};
```

**C# Code**:
```C#
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Hashtable book = new Hashtable();
        int[] result = new int[2];
        for(int i = 0; i < nums.Length; i++){
            if (book.ContainsKey(target - nums[i])){
                result[0] = (int)book[target - nums[i]];
                result[1] = i + 1;
                return result;
            }
            if (book.ContainsKey(nums[i])){
                book[nums[i]] = i + 1;
            }
            else{
                book.Add(nums[i], i + 1);
            }
        }
        return null;
    }
}
```
<br>

### <a name="2-add-two-numbers"></a>2 Add Two Numbers
> You are given two linked lists representing two non-negative numbers.
> The digis are stored in reverse order and each of their nodes contain a single digit.
> Add the two numbers and return it as a linked list.
>
> **`Input:`** `(2 -> 4 -> 3) + (5 -> 6 -> 4)`
>
> **`Output:`** `(7 -> 0 -> 8)`

**Idea**

Digits are stored in reverse order, that means `(2 -> 4 -> 3)` is `342`. When it reaches 10 after addition, the next node shall add 1 and current node shall only keep the unit number: `(3 -> 2) + (9 -> 1) = (2 -> 4)`; if one integer doesn't have more numbers, add the remaining digits to  result.

**Attention**: After both l1 and l2 reach to the end, check the carry. If carry != 0, add an additional node to the result. 



**C++ Code**
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *l3 = new ListNode(0);
        ListNode *p = l3;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p->next = new ListNode(mod);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p->next = new ListNode(mod);
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p->next = new ListNode(mod);
            p = p->next;
            l2 = l2->next;
        }
        if (carry > 0)
        p->next = new ListNode(carry);
        return l3->next;
    }
};
```

***C# Code***
```c#
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode l3 = new ListNode(0);
        ListNode p = l3;
        int carry = 0;
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p.next = new ListNode(mod);
            p = p.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            int sum = l1.val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p.next = new ListNode(mod);
            p = p.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            int sum = l2.val + carry;
            int mod = sum % 10;
            carry = sum / 10;
            p.next = new ListNode(mod);
            p = p.next;
            l2 = l2.next;
        }
        if (carry > 0)
        p.next = new ListNode(carry);
        return l3.next;
    }
}
```

<br>

### <a name="3-longest-substring-without-repeating-characters"></a>3 Longest Substring Without Repeating Characters
> Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

**Idea**

首先，这是个求最值的题，考虑dp。

遍历一遍字符串，每当遇到重复字符时便将start置为之前出现的这个字符的位置+1。

在每一次操作中都记录下下标位置，以便在之后重复时找到位置。

在每一次操作中比较目前长度和maxlen的大小，取最大值。

***C++ Code***
```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dp(256, -1);
        int result = 0, start = 0;
        for (int i = 0;i < s.length();i++) {
            if (dp[s[i]] >= start) start = dp[s[i]]+1;
            dp[s[i]] = i;
            result = max(result, i-start+1);
        }
        return result;
    }
};
```

***C# Code***
```C#
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int[] dp = new int[256];
        for (int i = 0;i < 256;i++) {
            dp[i] = -1;
        }
        int result = 0, start = 0;
        for (int i = 0;i < s.Length;i++) {
            if (dp[s[i]] >= start) start = dp[s[i]]+1;
            dp[s[i]] = i;
            result = Math.Max(result, i-start+1);
        }
        return result;
    }
}
```
<br>

### <a name="4-median-of-two-sorted-arrays"></a>4 Median of Two Sorted Arrays
> There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**Idea**

将找中位数问题=>泛化成找两个数列中第k大的数：

1. 比较两个数列的中间数大小

2. 若a[mid] <= b[mid] then return findKth(a+mid+1, m-mid-1, b, n, k-mid-1);

3. 若a[mid] >  b[mid] then return findKth(a, m, b+mid+1, n-mid-1,k-mid-1);

在每次findKth时，判断m是否为0以及k是否为1。
并且每次控制a串比b串短

***C++ Code***
```C++
class Solution {
public:
    double findKthElement(vector<int>::iterator a,int m,vector<int>::iterator b,int n,int k) {
        if (m > n) return findKthElement(b,n,a,m,k);
        if (m == 0) return b[k-1];
        if (k == 1) return min(a[0],b[0]);
        int mid_a = min(k/2,m);
        int mid_b = k - mid_a;
        if (a[mid_a-1] <= b[mid_b-1]) return findKthElement(a + mid_a,m - mid_a,b,n,k-mid_a);
        else return findKthElement(a,m,b+mid_b,n-mid_b,k-mid_b);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto a = nums1.begin();
        auto b = nums2.begin();
        int m = nums1.size();
        int n = nums2.size();
        int len = nums1.size() + nums2.size();
        if (len % 2 == 0) return 0.5*(findKthElement(a,m,b,n,len/2) + findKthElement(a,m,b,n,len/2+1));
        else return findKthElement(a,m,b,n,len/2+1);
    }
};
```

***C# Code***
```C#

```

### <a name="5-longest-palidromic-substring"></a>5 Longest Palidromic Substring
> Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


### <a name="6-zigzag-conversion">6 ZigZag Conversion

> The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

<pre>
P   A   H   N
A P L S I I G
Y   I   R
</pre>

> And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

<pre>
string convert(string text, int nRows);
</pre>

> convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

**Idea**

这种题找不到头绪可以找规律，从nRows = 3, nRows = 4, nRows = 5画出来能发现两个通式：

1. 第一行和最后一行，每列相隔 2 * (nRows - 1)

2. 中间的行，交替出现 2 * (nRows - i - 1) 和 2 * i

然后只要两个for循环，一个走行一个走列即可

***C++ Code***
```C++
class Solution{
public:
    string convert(string s, int numRows){
        string result;
        if (numRows == 1) return s;
        for (int i = 0;i < numRows;++i) {
            bool flag = true;
            for (int j = i;j < s.length();) {
                result.push_back(s[j]);
                if (i == 0 || i == numRows-1) {
                    
                    j += 2*(numRows - 1);
                }
                else {
                    if (flag) {
                        j += 2*(numRows - i - 1);
                    }
                    else {
                        j += 2*i;
                    }
                    flag = !flag;
                }
            }
        }
        return result;
    }
};
```

***C# Code***
```C#
public class Solution {
    public string Convert(string s, int numRows) {
        string result = "";
        if (s.Length == 1 || numRows == 1) return s;
        for (int i = 0;i < numRows;++i) {
            bool flag = true;
            for (int j = i;j < s.Length;) {
                result += s[j];
                if (i == 0 || i == numRows-1) {
                    j += 2 * (numRows - 1);
                }
                else {
                    if (flag) {
                        j += 2 * (numRows - i - 1);
                    }
                    else {
                        j += 2 * i;
                    }
                    flag = !flag;
                }
            }
        }
        return result;
    }
}
```

### <a name = "7-reverse-integer">7 Reverse Integer
> Reverse digits of an integer.

> ***Example1:*** x = 123, return 321

> ***Example2:*** x = -123, return -321

**Attention:** Watch out the case of overflow,  Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

**Idea**

从最简单的反转123考虑，每一次保留个位数加入新数做累积累加 result = result*10 + mod;

1.考虑第一个问题：负号，实际上不用考虑 -321 = -3*100 + -2*10 + -1
2.考虑第二个went：溢出，若溢出，那么溢出的结果 /10 一定不能复原，因此每次都保存temp 验证result/10 == temp? 即可

***C++ Code***
```C++
class Solution {
public:
    int reverse (int n) {
        int result = 0;
        int mod = 0;
        int temp = 0;
        while (n){
            mod = n % 10;
            temp = result;
            result = result * 10 + mod;
            if (result / 10 != temp) return 0;
            n /= 10;
        }
        return result;
    }
};
```

***C# Code***
```C#
public class Solution {
    public int Reverse(int x) {
        int result = 0;
        int mod = 0;
        int temp = 0;
        while (x != 0){
            mod = x % 10;
            temp = result;
            result = result * 10 + mod;
            if (result / 10 != temp) return 0;
            x /= 10;
        }
        return result;
    }
}
```

###<a name = "8-string-to-integer">8 String to Integer (atoi)
> Implement atoi to convert a string to an integer.

> ***Hint:*** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

> ***Notes:*** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

**Idea**

***C++ Code Solution 1 using istringstream***
```C++
class Solution {
public:
    int myAtoi(string str) {
        if (str=="") return 0;
        istringstream iss(str);
        int a;
        iss>>a;
        return a;
    }
};
```

###<a name = "9-palindrome-number">9 Palindrome Number
> Determine whether an integer is a palindrome. Do this without extra space.

**Idea**
* Solution 1: I used a string to store this int, and check the head and tail if they are the same, otherwise report false. But it will use O(n) space complexity.

* Solution 2: I used the reverse integer function to check it, but it will not handle the overflow case although it can still pass the OJ.

* Solution 3: I follow the thought from solution 1 without construct a string, only use two pointers.

***C++ Code Solution 1***
```C++
class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string str = to_string(x);
        int n = (int)str.length();
        int i = 0;
        while (i < n/2) {
            if (str[i] != str[n-i-1]) return false;
            i++;
        }
        return true;
    }
};
```

***C++ Code Solution 2***
```C++
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int result = 0;
        int mod = 0;
        int save = x;
        while (x) {
            mod = x % 10;
            result = result * 10 + mod;
            x /= 10;
        }
        return result == save;
    }
};
```

***C++ Code Solution 3***
```C++
class Solution3 {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int temp = x;
        int digit = 1;
        while (temp >= 10) {
            digit *= 10;
            temp /= 10;
        }
        while (x) {
            int left = x / digit;
            int right = x % 10;
            if (left != right) return false;
            x = (x % digit) / 10;
            digit /= 100;
        }
        
        return true;
    }
};
```

###<a name = "11-container-with-most-water"></a>11 Container With Most Water

> Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

> ***Note:*** You may not slant the container.

**Idea**
Greedy Algorithm, start from the outer two pointers, and compare the height, move the pointer which is smaller.

***C++ Code***
```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int result = 0;
        while (i < j) {
            result = max(result, min(height[i],height[j])*(j-i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return result;
    }
};
```

***C# Code***
```C#
public class Solution {
    public int MaxArea(int[] height) {
        int i = 0;
        int j = height.Length - 1;
        int result = 0;
        while (i < j) {
            result = Math.Max(result, Math.Min(height[i],height[j])*(j-i));
            if (height[i]<height[j]) i++;
            else j--;
        }
        return result;
    }
}
```

###<a name=""12-integer-to-roman></a>12 Integer to Roman

> Given an integer, convert it to a roman numeral.

> Input is guaranteed to be within the range from 1 to 3999.

**Idea** 找规律填数字，每次循环注意digit分为四种情况即可: <1-3>,<4>,<5-8>,<9>

***C++ Code***
```C++
class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<char> roman = {'M','D','C','L','X','V','I'};
        int t = num / 1000 + 1;
        num = t>0 ? num%1000 : t;
        while (--t) {
            result += roman[0];
        }
        int flag = 100;
        for (int i = 0;i < 3;i++,flag /= 10) {
            if (num < flag) continue;
            int digit = num / flag;
            if (digit == 9) {
                result = result + roman[2*i+2]+ roman[2*i];
            }
            else if (digit >= 5) {
                result = result + roman[2*i+1];
                while (--digit >= 5) {
                    result = result + roman[2*i+2];
                }
            }
            else if (digit == 4) {
                result = result + roman[2*i+2] + roman[2*i+1];
            }
            else {
                while (--digit >= 0) {
                    result = result + roman[2*i+2];
                }
            }
            num %= flag;
        }
        return result;
    }
};
```

###<a name="13-roman-to-integer"></a>13 Roman to Integer

> Given a roman numeral, convert it to an integer.

> Input is guaranteed to be within the range from 1 to 3999.

**Idea** 
* 先将罗马数字映射进map，注意map的initialization, pair可以直接用{ }初始化。
* 遍历字符串，分为三种情况，一种前比后大直接加，一种前比后小要减去，一种前后相等要累积 之后才能判断加减。
* 用一个temp数字来保存之前相等的累计数。

***C++ Code***

```C++
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int temp = 0;
        for (int i = 0;i < s.length() - 1;i++) {
            if (mp[s[i]] == mp[s[i+1]]) temp += mp[s[i]];
            else if (mp[s[i]] > mp[s[i+1]]) {
                result = result + temp + mp[s[i]];
                temp = 0;
            }
            else {
                result = result - temp - mp[s[i]];
                temp = 0;
            }
        }
        result += mp[s[s.length()-1]] + temp;

        return result;
    }
};
```

###<a name = "14-longest-common-prefix">14 Longest Common Prefix

> Write a function to find the longest common prefix string amongst an array of strings.

**Idea** Compare every character in all strings.

***C++ Code***
```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string result = "";
        for (int i = 0;i < strs[0].length();i++) {
            char check = strs[0][i];
            for (int j = 0;j < strs.size();j++) {
                if (check != strs[j][i] || i == strs[j].length()) return result;
            }
            result += check;
        }
        return result;
    }
};
```

***C# Code***
```C#
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs.Length == 0) return "";
        if (strs.Length == 1) return strs[0];
        string result = "";
        for (int i = 0;i < strs[0].Length;i++) {
            char check = strs[0][i];
            for (int j = 0;j < strs.Length;j++) {
                if (i == strs[j].Length || check != strs[j][i] ) return result;
            }
            result += check;
        }
        return result;
    }
}
```

###<a name = "15-3-sum"></a>15 3 Sum

> Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

- Elements in a triplet (a,b,c) must be in **non-descending order**. (ie, a ≤ b ≤ c)

- The solution set **must not contain duplicate triplets**.
    
    
    
  		For example, given array S = {-1 0 1 2 -1 -4},
    	A solution set is:
    	(-1, 0, 1)
    	(-1, -1, 2)
    

**Idea** 
* At first, we can think of the naive implemention with O(n^3): brute force
* Then we can select one number as -target, then travese using hashmap (Two Sum)
* However, we found the requirments that in non-descending order, so we should sort at first, but when dealing sorted array we can use two pointer method rather than hashmap, which can save the space complexity.
* Watch out for duplicates. I added three lines to keep the three number from duplicates.


***C++ Code
```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(),nums.end());
        for (int i = 0;i < nums.size() - 2;i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;                //In case of duplicates
            int target = - nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] == target) {
                    vector<int> line({nums[i],nums[start],nums[end]});
                    result.push_back(line);
                    start++;
                    end--;
                    while (nums[start] == nums[start-1]) start ++;  //In case of duplicates
                    while (nums[end]==nums[end+1]) end--;           //In case of duplicates
                }
                else if (nums[start] + nums[end] > target) end--;
                else start++;
            }
        }
        return result;
    }
};
```

###<a name="3-sum-closet"></a>16 3 Sum Closet

> Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

- For example, given array S = {-1 2 1 -4}, and target = 1.

- The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

**Idea** Just follow the 3 Sum to find the closet

***C++ Code***
```C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int distance = INT32_MAX;
        int result = 0;
        if (nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        for (int i = 0;i < nums.size()-2;i++) {
            int newtarget = target - nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while (start < end) {
                if (abs(newtarget - nums[start] - nums[end]) < distance) {
                    distance = abs(newtarget - nums[start] - nums[end]);
                    result = nums[start] + nums[end] + nums[i];
                }
                if (distance == 0) return target;
                else if (nums[start] + nums[end] > newtarget) end--;
                else start++;
            }
        }
        return result;
    }
};
```

###<a name = "17-letter-combinations-of-a-phone-number"></a>17 Letter Combinations of a Phone Number

>  Given a digit string, return all possible letter combinations that the number could represent.

> A mapping of digit to letters (just like on the telephone buttons) is given below.

<pre>

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

</pre>

> Note:

> Although the above answer is in lexicographical order, your answer could be in any order you want.

**Idea** Backtracking

backtracking的标准写法: 

- 写一个helper，helper第一个部分判断是否combinations完毕，是的话return

- 第二个部分添加push_back这个字符，执行本函数并将位置加一，再pop_back之前那个字符

**Complexity**
O(k ^ n), k is possible choice of each digit, n is the length of digits

***C++ Code***
```C++
class Solution {
public:
    void letterCombinationsHelper(vector<string> &result, vector<string> letters,string digits, string &line, int start) {
        if (start == digits.length()) {
            result.push_back(line);
            return;
        }
        for (int i = 0;i < letters[digits[start]-'0'].length();i++) {
            line.push_back(letters[digits[start]-'0'][i]);
            letterCombinationsHelper(result,letters,digits,line,start+1);
            line.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> letters({"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        string line = "";
        if (digits.length() == 0) return result;
        letterCombinationsHelper(result,letters,digits,line,0);
        return result;
    }
};
```

###<a name="18-4-sum">18 4 Sum

>Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

>Note:

- Elements in a quadruplet (a,b,c,d) must be in **non-descending order**. (ie, a ≤ b ≤ c ≤ d)

- The solution set must **not contain duplicate quadruplets**.
 
 
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

        A solution set is:
   	    (-1,  0, 0, 1)
        (-2, -1, 1, 2)
        (-2,  0, 0, 2)
    
<br>

**Idea** Like 3 sum, still be carefull for duplicates with 4 individual number;

**Complexity** Time O(n^3) Space O(n^2)

```C++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) return result;
    sort(nums.begin(),nums.end());
    for (int i = 0;i < nums.size() - 3;i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1;j < nums.size() - 2;j++) {
            if (j>i+1 && nums[j] == nums[j-1]) continue;
            int newtarget = target - nums[i] - nums[j];
            int start = j + 1;
            int end = (int)nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] == newtarget) {
                    vector<int> line({nums[i],nums[j],nums[start],nums[end]});
                    result.push_back(line);
                    start ++;
                    end--;
                    while (nums[start] == nums[start-1]) start++;
                    while (nums[end] == nums[end+1]) end--;
                }
                else if (nums[start] + nums[end] > newtarget) end--;
                else start++;
            }
        }
    }
    return result;
}
};
```

###<a name="19-remove-nth-node-from-end-of-list"></a>19 Remove Nth Node From End of List

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

***Note:***

Given n will always be valid.
Try to do this in one pass.

**Idea** Create a fast node which is n step fast than head, and for corner case i would advise use dummynode.

***C++***
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummynode(0);
        dummynode.next = head;
        ListNode *fast = head;
        while (n--) {
            fast = fast->next;
        }
        head = &dummynode;
        while (fast) {
            head = head->next;
            fast = fast->next;
        }
        head->next = head->next->next;
        return dummynode.next;
    }
};
```

###<a name="20-valid-parentheses"></a>20 Valid Parentheses

> Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

> The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

**Idea** Use a stack, and in the loop, judge the top of stack whether it matches the current bracket.

***C++ Code***
```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (int i = 0;i < s.length();i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') ss.push(s[i]);
            else {
                if (s[i] == ')') {
                    if (ss.empty() || ss.top() != '(') return false;
                    ss.pop();
                }
                
                else if (s[i] == '}') {
                    if (ss.empty() || ss.top() != '{') return false;
                    ss.pop();
                }
                
                else if (s[i] == ']') {
                    if (ss.empty() || ss.top() != '[') return false;
                    ss.pop();
                }
            }
        }
        return ss.empty();
    }
};
```

###<a name="21-merge-two-sorted-lists"></a>21 Merge Two Sorted Lists

> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**Idea** Naive implemetion by creating a new list node, be careful for dummynode.

***C++ Code ***
```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummynode(0);
        ListNode *l3 = &dummynode;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            }
            else { 
                l3->next = l2; 
                 l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l1) l3->next = l1;
        else l3->next = l2;
        return dummynode.next;
    }
};
```

###<a name="22-generate-parantheses"></a>22 Generate Parentheses

> Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

> For example, given n = 3, a solution set is:

        "((()))", "(()())", "(())()", "()(())", "()()()"

**Idea** Backtracking
It's like combination, for example of 3, it's like combinations of (),(),(),(),(),() but it has constraint.

You should first add '(' and the count of ')' never exceed count of '('.

Then in the helper function: 

we can consider the combination of "((()))", and use left right pointer for constraint.

Then follow the normal backtracking method to fill the function, be care to replace for loop with two if clause.

***C++ Code***
```C++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string line;
        int count = n;
        int left = 0, right = 2*n - 1;
        generate(result,line,left,right,count);
        return result;
    }
    void generate(vector<string> &result, string &line, int left, int right,int x)
    {
        if (left > right) {
            result.push_back(line);
            return;
        }
        if (left < x) {
            line.push_back('(');
            generate(result,line,left+1,right,x);
            line.pop_back();
        }
        if (2*x - right - 1 < left){
            line.push_back(')');
            generate(result,line,left,right-1,x);
            line.pop_back();
        }
    }
};
```

###<a name="24-swap-nodes-in-pairs"></a>24 Swap Nodes in Pairs
> Given a linked list, swap every two adjacent nodes and return its head.

> For example,

> Given 1->2->3->4, you should return the list as 2->1->4->3.

> Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

**Idea** Swap one by one, remember using dummy node;

***C++***

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next ==NULL) return head;
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        while (head && head->next) {
            temp->next = head->next;   //these three lines are used to swap sequence
            head->next = head->next->next;
            temp->next->next = head;
            
            temp = head;               // these two lines are used to move forward
            head = head->next;
        }
        temp->next = head;
        return dummy.next;
    }
};
```

###<a name="26-remove-duplicates-from-sorted-array"></a>26 Remove Duplicates from Sorted Array

> Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

> Do not allocate extra space for another array, you must do this in place with constant memory.

> For example,

> Given input array nums = [1,1,2],

> Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter 
 
> what you leave beyond the new length.

**Idea**

***C++ Solution 1 using dynamic vector***
```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1;
        for (int i = 1,n = 1;n < nums.size();n++) {
            if (nums[i] == nums[i-1]) {
                int temp = nums[i];
                nums.erase(nums.begin()+i);
                nums.push_back(temp);
            }
            else {
                ++count;
                ++i;
            }
        }
        return count;
    }
};
```

***C++ Solution 2 using normal arrays*** 
```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1;
        for (int i = 1,p = 1;i < nums.size();i++) {      //Two Pointers to store the current index and should store index
            while (nums[i] == nums[i-1]) i++;
            if (i< nums.size()) {
                nums[p] = nums[i];
                count++;
                p++;
            }
        }
        return count;
    }
};
```

###<a name=""27-remove-element></a>27 Remove Element

> Given an array and a value, remove all instances of that value in place and return the new length.

> The order of elements can be changed. It doesn't matter what you leave beyond the new length.

**Idea** Two pointer is the best solution

***C++ Code***
```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int count = 0;
        for (int i = 0;i < nums.size();++i) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                ++count;
            }
        }
        return count;
    }
};
```

###<a name = "28-implement-strstr"></a>28 Implement strStr()

> Implement strStr().

> Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**Idea** We don't need to implement kmp algorithm usually. We can figure out the for loop by drawing "northwestern" -> "west"
Two for loop will be useful.

***C++***
```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;
        for (int i = 0;i < haystack.length() - needle.length() + 1;i++) {
            for (int j = 0;j < needle.length();j++) {
                if (haystack[i+j] != needle[j]) break;
                if (j == needle.length()-1) return i;
            }
        }
        return -1;
    }
};
```

###<a name="29-divide-two-integers"></a>29 Divide Two Integers

> Divide two integers without using multiplication, division and mod operator.

> If it is overflow, return MAX_INT.

**Idea** 

- For example, if we want to find 64 / 2; we can multiple 2 with 2 until it exceed 64, then we can get the answer 32 by loop five times.

- If we want to find 127 / 2, we can follow the step 1 and then use minus, 63 - 2 - 2 - ... 2 < 0, we can get 31 by loop 31 times.

- When the dividend becomes larger, the complexity will exceed as O(n), so we need to use O(log N) again, we use two while loop to accomplish these result.

***C++***
```C++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};
```

###<a name = "31-next-permutation"></a>31 Next Permutation

> Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

> If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

> The replacement must be in-place, do not allocate extra memory.

> Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

<pre>
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
</pre>

**Idea**  

- For example  4,8,7,6,3 => 6,3,4,7,8: 因为后四位数已成最大，只能把第一位数与之后的一位比4稍大的数交换，再将后缀正序。
- 1.从后往前，找到第一个 A[i-1] < A[i]的。也就是第一个排列中的  6那个位置，可以看到A[i]到A[n-1]这些都是单调递减序列。
- 2.从 A[n-1]到A[i]中找到一个比A[i-1]大的值（也就是说在A[n-1]到A[i]的值中找到比A[i-1]大的集合中的最小的一个值）
- 3.交换 这两个值，并且把A[n-1]到A[i]排序，从小到大。

***C++ Code***

```C++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int left = (int)nums.size()-2;
        while (left >= 0 && nums[left] >= nums[left+1]) --left;
        if (left<0) {sort(nums.begin(),nums.end());return;}
        int right = (int)nums.size()-1;
        while (right > left && nums[right] <= nums[left]) right--;
        swap(nums[left],nums[right]);
        sort(nums.begin() + left+1,nums.end());
    }
};
```

###<a name="46-permutations"></a>46 Permutations
> Given a collection of numbers, return all possible permutations.

> For example,

> [1,2,3] have the following permutations:

> [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

**Idea** Using swap in permutations, and using push_back in combinations. 
Difference, in the for loop, (int i = start) (permutations) while (int i = 0) (combinations)

*** C++ Code using swap***
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(result,nums,0);
        return result;
    }
    void permuteHelper(vector<vector<int>> &result, vector<int>& nums,int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start;i < nums.size();i++) {
            swap(nums[i],nums[start]);
            permuteHelper(result,nums,start + 1);
            swap(nums[i],nums[start]);
        }
    }
};
```

***C++ Code without using swap***
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> line;
        vector<int> visited(nums.size(),0);
        permuteHelper(result,nums,line,visited,0);
        return result;
    }
    
    void permuteHelper(vector<vector<int>> &result, vector<int>& nums,vector<int> &line,vector<int> &visited, int start) {
        if (start == nums.size()) {
            result.push_back(line);
            return;
        }
        for (int i = 0;i < nums.size();i++) {
            if (visited[i]!=0) continue;  // 防止出现 (1,1,1) (2,2,2) (3,3,3)
            line.push_back(nums[i]);
            visited[i] = 1;
            permuteHelper(result,nums,line,visited,start+1);
            line.pop_back();
            visited[i] = 0;
        }
    }
};
```

###<a name = "47-permutations-ii"></a>47 Permutations II

> Given a collection of numbers that might contain duplicates, return all possible unique permutations.

> For example,
> [1,1,2] have the following unique permutations:
> [1,1,2], [1,2,1], and [2,1,1].

**Idea** 
- 跟 Permutations的解法一样，就是要考虑“去重”。先对数组进行排序，这样在DFS的时候，可以先判断前面的一个数是否和自己相等，相等的时候则前面的数必须使用了，自己才能使用，这样就不会产生重复的排列了。

***C++ Code without using swap***
```C++
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<vector<int>> result;
        vector<int> line;
        vector<int> visited(num.size(),0);
        sort(num.begin(),num.end());
        permutation(num,0,visited,result,line);
        return result;
    }
    void permutation(vector<int> &num,int start,vector<int> &visited,vector<vector<int>> &result,vector<int> &line)
    {
        
        if (start==num.size())
        {
            result.push_back(line);
            return;
        }
        for (int i=0;i<num.size();i++)
        {
            if (visited[i]==0){  // 防止出现 (1,1,1) (2,2,2) (3,3,3)
                if(i>0 && num[i] == num[i-1] && visited[i-1] ==0) continue;  //防止得到相同结果，必须之前使用过 才能使用
                visited[i]=1;
                line.push_back(num[i]);
                permutation(num,start+1,visited,result,line);
                line.pop_back();
                visited[i]=0;
            }
            
        }
    }
};
```

###Others

###<a name="1-fibonacci"></a>1 Fibonacci

***Recursive C++ Code***
```C++
int recursive(int x){
    if (x == 0) return 0;
    if (x == 1) return 1;
    cout << x << " ";
    return recursive(x-1) + recursive(x-2);
}
```
***Time:*** T(n)=T(n−1)+T(n−2)+Θ(1) ==> O(2^n)

***Space*** O(1)? O(2^n)? 

It should be O(n), as we should draw the recursion tree, we will find it may be O(2^n), but in the stack frame.
For example when Fib(2) = Fib(1) + Fib(0) done, the stack memory of Fib(1) and Fib(0) will return so the memory will pop back, then the maximum stack memory should be Fib(n-1) + Fib(n-2) + ... + Fib(1) = O(n);

***Iterative C++ Code***
```C++
int iterative(int n) {
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    for (int i = 2;i <= n;i++) {
        dp.push_back(dp[i-1] + dp[i-2]);
    }
    return dp[n];
}
```

***Time:*** O(n)

***Space:*** O(n)
