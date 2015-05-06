//
//  main.cpp
//  zenefits
//
//  Created by Biao He on 4/25/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the function below.
 */
int gcd(int a, int b) {     //call the function of greatest common divisor
    while (1) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b) {     //call the function of largest common multiple
    int temp = gcd(a,b);
    return temp ? (a / temp * b) : 0;
}

int nlcm(vector<int>& a, int n) {    //call the function of n largest common multiple
    if (n == 1) {
        return a[0];
    }
    else return lcm(a[n-1],nlcm(a,n-1));
}

int hammingWeight (int n) { // Calculate the number of 1 bits
    int sum = 0;
    while (n) {
        sum += n&1;
        n = n>>1;
    }
    return sum;
}

int countUneatenLeaves(int N, vector < int > A) {
    int n = int(A.size());
    int count = 0;
    vector <int> temp;
    for (int mask = 1; mask< 1<<n; mask++) {
        
        for (int i=0;i<A.size();i++) {
            
            if (mask & (1<<i)) {
                temp.push_back(A[i]);
            }
        }
        int oddeven = hammingWeight(mask);
        int lcmresult=nlcm(temp,oddeven);
        if (oddeven%2 == 1) {      //Which means the set has odd number
            if (lcmresult<=N) count += N/lcmresult;
        }
        else {                     //Which means the set has even number
            if (lcmresult<=N) {
                count -= N/lcmresult;
            }
        }
        temp.resize(0);
    }
    return N-count;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A={2,4,5};
    int abc = countUneatenLeaves(20, A);
    std::cout << abc;
    return 0;
}

class Solution {
public:
    int minDepth(TreeNode *root) {
        int mind = 100;
        int count=1;
        dfs(root->left,count,mind);
        return mind;
    }
    
    void dfs(TreeNode *root,int count) {
        if (root==NULL)
        {
            mind = min(count,mind);
            return;
        }
        if (root->left) dfs(TreeNode->left,count+1,mind);
        if (root->right) dfs(TreeNode->right,count+1,mind);
    }
};




