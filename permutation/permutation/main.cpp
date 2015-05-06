//
//  main.cpp
//  permutation
//
//  Created by Biao He on 4/14/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<std::vector<int>> permute(std::vector<int> &num)
    {
        permutation(num,0);
        return ans;
    }
    
    void permutation(std::vector<int> &num,int start)
    {
        if (start==num.size())
        {
            ans.push_back(num);
        }
        for (int i=start;i<num.size();i++)
        {
            std::swap(num[start],num[i]);
            permutation(num,start+1);
            std::swap(num[start],num[i]);
        };
    }
};

int main(int argc,  char * argv[]) {
    // insert code here...
    Solution s1;
    std::vector<int> num = {1,2,3,4};
    std::vector<std::vector<int>> answer=s1.permute(num);
    for(int i=0;i<24;i++)
    {for(int j=0;j<4;j++)
    {std::cout << answer[i][j];}std::cout << "\n";}
    return 0;
}


