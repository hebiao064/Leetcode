## Overview

* [1 Two Sum](#1-two-sum)
* [2 Add Two Numbers](#2-add-two-numbers)
* [3 Longest Substring Without Repeating Characters](#3-longest-substring-without-repeating-characters)

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
