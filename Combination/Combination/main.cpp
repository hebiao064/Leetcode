//
//  main.cpp
//  Combination
//
//  Created by Biao He on 5/2/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void combine(int n, int k, vector<vector <int>> &result) {
        
        vector<int> num;
        combination(num,1,n,k,result);
    }
    
    void combination(vector<int> &num,int start,int n,int k,vector<vector <int>> &result)
    {
        if (k==0)
        {
            result.push_back(num);
        }
        for (int i=start;i<=n;i++)
        {
            num.push_back(i);
            combination(num,i+1,n,k-1,result);
            num.pop_back();
        };
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s1;
    vector<vector<int>> result;
    s1.combine(4,2,result);
    
    std::cout << result[0][0]<<result[0][1]<<result[0][2]<<endl;
    std::cout << result[1][0]<<result[1][1]<<result[1][2]<<endl;
    std::cout << result[2][0]<<result[2][1]<<result[2][2]<<endl;
    std::cout << result[3][0]<<result[3][1]<<result[3][2]<<endl;
    std::cout << result[4][0]<<result[4][1]<<result[4][2]<<endl;
    std::cout << result[5][0]<<result[5][1]<<result[5][2]<<endl;
    //std::cout << result[6][0]<<result[6][1]<<result[6][2]<<endl;

    return 0;
}




