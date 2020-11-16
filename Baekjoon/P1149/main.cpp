//
//  main.cpp
//  P1149
//
//  Created by 김지은 on 2020/11/16.
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
    
    int rgb[1000][3];
    int N;
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    
    int dp[1000][3];
    
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];
    
    for (int i=1; i<N; i++) {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + rgb[i][2];
    }
    
    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2]}) << "\n";
    
    
    return 0;
}
