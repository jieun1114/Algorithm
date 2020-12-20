//
//  main.cpp
//  P2217
//
//  Created by 김지은 on 2020/12/20.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>


using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    
    int lope[n];
    
    for (int i=0; i<n; i++) {
        cin >> lope[i];
    }
    
    sort(lope,lope+n,greater<int>());
    
    long long w = lope[0];
    
    for (int i=1; i<n; i++) {
        if(lope[i]*(i+1) > w)
            w = lope[i]*(i+1);
    }
    
    cout << w << "\n";

    return 0;

}
