//
//  main.cpp
//  Merge Sort
//
//  Created by Biao He on 5/6/15.
//  Copyright (c) 2015 Biao He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(int *a,int low,int high,int mid) {
    int c[high+1];
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j<=high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
            k++;
        }
        else {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= mid) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j <= high) {
        c[k] = a[j];
        j++;
        k++;
    }
    for (i = low;i < k;i++)
    {
        a[i]=c[i];
    }
    return;
}

void mergesort(int *a,int low,int high) {
    int mid;
    if (low<high) {
        mid = (low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int a[]={5,3,2,1,4,7,8,9,0,6,9,-12,12,-13,14};
    mergesort(a,0,14);
    int b[10]={1,3,5,7,9,2,4,6,8,10};
    merge(b,0,9,4);
    for (int i=0;i<15;i++) {
        cout << a[i]<<endl;
    }
    return 0;
}

