//
//  main.cpp
//  P10816
//
//  Created by 김지은 on 2020/11/26.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int A[500000];

int lowSearch(int start, int end, int val){
    
    if(start>end)
        return -1;
    
    int mid = (start + end)/2;
    if(A[mid]==val){
        if(mid>0 && A[mid-1]==val)
            return lowSearch(start, mid-1, val);
        else
            return mid;
    }
    else if(A[mid]>val)
        return lowSearch(start, mid-1, val);
    else
        return lowSearch(mid+1, end, val);
}


int highSearch(int start, int end, int val){
    
    if(start>end)
        return -1;
    
    int mid = (start + end)/2;
    if(A[mid]==val){
        if(mid<end && A[mid+1]==val)
            return highSearch(mid+1, end, val);
        else
            return mid;
    }
    else if(A[mid]>val)
        return highSearch(start, mid-1, val);
    else
        return highSearch(mid+1, end, val);
}



int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int N, M;
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    sort(A,A+N);
    cin >> M;
    int num;
    for (int i=0; i<M; i++) {
        cin >> num;
        int cnt = 0;
        if(highSearch(0, N-1, num)!=-1)
            cnt = highSearch(0, N-1, num)-lowSearch(0, N-1, num)+1;
        cout << cnt << " ";
    }
    
    return 0;
}
