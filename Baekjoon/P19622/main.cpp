//
//  main.cpp
//  P19622
//
//  Created by 김지은 on 2020/09/25.
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
    
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> meet;
    
    for (int i=0; i<n; i++) {
        int s,e,p;
        cin >> s >> e >> p;
        meet.push_back({{s,e},p});
    }
    
    int dp[n][2];
    dp[0][1] = meet[0].second;
    dp[0][0] = 0;
    
    for (int i=1; i<n; i++) {
        dp[i][1] = dp[i-1][0] + meet[i].second;
        dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
    }
    
    cout << max(dp[n-1][1],dp[n-1][0]) << "\n";
    
    return 0;
}
