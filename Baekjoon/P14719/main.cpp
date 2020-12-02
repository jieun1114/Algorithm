//
//  main.cpp
//  P14719
//
//  Created by 김지은 on 2020/09/22.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int H, W;
    int answer = 0;
    int rain[500];

    cin >> H >> W;
    for (int i=0; i<W; i++) {
        cin >> rain[i];
    }
    
    for (int i=1; i<W-1; i++) {
        int left = rain[i], right = rain[i];
        for (int l=0; l<i; l++) {
            left = max(left,rain[l]);
        }
        for (int r=i+1; r<W; r++) {
            right = max(right,rain[r]);
        }
        
        answer += min(left,right) - rain[i];
        
    }
    
    cout << answer << "\n";
    
    return 0;
}
