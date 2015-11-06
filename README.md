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
