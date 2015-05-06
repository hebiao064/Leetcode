//
//  main.cpp
//  Excel Sheet Column Title
//
//  Created by Biao He on 5/4/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/*string convertToTitle(int n) {
    string result = "";
    while (n) {
        int elem = n % 26;
        
        n /= 26;
    }
    return result;
}*/

int main(int argc, const char * argv[]) {
    // insert code here...
    string result = "";
    int n = 1;
    while (n) {
        int elem = n % 26;
        result.insert(result.begin(),char('A'+elem-1));
        n /= 26;
    }
    std::cout << result << endl;
    //std::cout << convertToTitle(1)<<endl;
    return 0;
}
