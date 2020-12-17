//
//  main.cpp
//  P10610
//
//  Created by 김지은 on 2020/12/17.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    string N;
    cin >> N;
    
    long long sum = 0;
    for (char c : N) {
        sum += c - '0';
    }
    sort(N.begin(),N.end(),greater<int>());
    
    if(N.back()=='0' && sum%3==0)
        cout << N << "\n";
    else
       cout << -1 << "\n";

    return 0;

}
