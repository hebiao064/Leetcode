### Overview

* [1 Two Sum](#1-two-sum)
* [2 Add Two Numbers](#2-add-two-numbers)

<br>
### <a name="1-two-sum"></a>1 Two Sum

>Given an array of integers, find two numbers such that they add up to a specific target number.

>The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

>You may assume that each input would have exactly one solution.

>Input: numbers={2, 7, 11, 15}, target=9

>Output: index1=1, index2=2

**Solution C++**: Use HashMap to record the number one by one and check if it exist the target at the same time, only use one loop.

**Time Complexity** O(n)

**Space Complexity** O(n)

**Tags** HashMap

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

**Solution C#**:
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
