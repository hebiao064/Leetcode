//
//  main.cpp
//  House Robber
//
//  Created by Biao He on 4/30/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int rob(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i=2;i<nums.size();i++) {
        dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[nums.size()-1];
}

int robusingo1(vector<int>& nums) {
    int odd = nums[0];
    int even = max(nums[0],nums[1]);
    for (int i=2;i<nums.size();i++) {
        if (i%2==0) odd=max(odd+nums[i],even);
        else even=max(even+nums[i],odd);
    }
    return max(odd,even);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={1,2,3,4,5,6,7};
    //std::cout<<a[1]<<endl;
    cout<< robusingo1(a);
}


