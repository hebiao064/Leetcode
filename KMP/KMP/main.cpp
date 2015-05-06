//
//  main.cpp
//  KMP
//
//  Created by Biao He on 4/30/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int kmp(string haystack,string needle,int *p) {
    int j=-1;
    for (int i=0;i<haystack.length();i++) {
        while (j>-1 && needle[j+1]!=haystack[i]) j=p[j];
        if (needle[j+1]==haystack[i]) j++;
        if (j==needle.length()-1) return i-j;
    }
    return -1;
}

void pattern(string needle,int *p) {
    p[0]=-1;
    int j=-1;
    for (int i=1;i<needle.length();i++) {
        while (j>-1 && needle[j+1]!=needle[i]) j=p[j];
        if (needle[j+1]==needle[i]) j++;
        p[i]=j;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string a = "abaabbaaabbbaaaabbbb";
    std::string b = "aaaa";
    int *p = new int[b.length()];
    pattern(b,p);
    std::cout << *p++<<*p++<<*p++<<*p++<<"what's wrong"<<endl;
    p=p-4;
    std::cout << endl;
    std::cout << kmp(a,b,p)<<endl;
    delete p;
    return 0;
}
