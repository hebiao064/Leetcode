//
//  main.cpp
//  Vector
//
//  Created by Biao He on 4/22/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution1
{
public:
    vector<int> twoarray(std::vector<int> &A,std::vector<int> &B)
    {
        std::unordered_map<int,int> mappingA;
        //std::unordered_map<int,int> mappingAll;
        vector<int> result;
        int lengthA = A.size();
        int lengthB = B.size();
        for (int i=0;i<lengthA;i++)
        {
            mappingA[A[i]]++; //count the appearance of A[]
            //cout<<A[i]<<","<<mappingA[A[i]]<<endl;
        }
        std::unordered_map<int,int> mappingAll (mappingA.begin(),mappingA.end());
        for (int i=0;i<lengthB;i++)
        {
            mappingAll[B[i]]++;//count the appearance of B[] plus the A[]
            //cout<<B[i]<<","<<mappingAll[B[i]]<<endl;
        }
        //Push Back the result
        for (std::unordered_map<int,int>::iterator it1=mappingAll.begin();it1!=mappingAll.end();it1++)
        {
            std::unordered_map<int,int>::iterator it2 = mappingA.find(it1->first);
            if (it2==mappingA.end())
            {
                for(int i=0;i<(it1->second);i++)
                {result.push_back(it1->first);}
            }
            else if (mappingAll[it1->first]==mappingA[it2->first])
            {for(int j=0;j<(it1->first);j++)
            {result.push_back(it1->first);}
            }
        }
        return result;
    }
};

class Solution2
{
public:
    vector<int> twoarray(std::vector<int> &A,std::vector<int> &B)
    {
        std::unordered_map<int,int> mappingA;
        vector<int> result;
        int lengthA = A.size();
        int lengthB = B.size();
        
        for (int i=0;i<lengthA;i++)   //Push the value of A into map
        {
            mappingA[A[i]]++; //count the appearance of A[]
        }
        
        for (int j=0;j<lengthB;j++)   //Push the B value into result while non-exist in A
        {
            if (mappingA[B[j]]>0) mappingA[B[j]]=-1;
            if (mappingA[B[j]]==-1) continue;
            else result.push_back(B[j]);
        }
        
        //Push the remaining map A into result, ignore the duplicates with B
        for (std::unordered_map<int,int>::iterator it = mappingA.begin();it!=mappingA.end();it++)
        {
            for(int j=0;j<(it->second);j++)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s1;
    Solution2 s2;
    std::vector<int> A = {1,1,1,3,3,5,7};
    std::vector<int> B = {1,1,2,4,4,4,5};
    std::vector<int> finalresult1 = s1.twoarray(A,B);
    std::vector<int> finalresult2 = s2.twoarray(A,B);
    for (int i=0;i<finalresult2.size();i++)
    {
        std::cout<< "hello"<<endl;
        std::cout<<finalresult2[i]<<endl;
    }
}
