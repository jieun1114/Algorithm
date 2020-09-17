//
//  main.cpp
//  P15486
//
//  Created by 김지은 on 2020/09/17.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;
    int T[N+1];
    int P[N+1];
    for (int i=1; i<=N; i++) {
        cin >> T[i] >> P[i];
    }
    
    long long dp[N+2];
    dp[N+1] = 0;
    
    for (int i=N; i>=1; i--) {
        if(i+T[i] > N+1){
            dp[i] = dp[i+1];
        }else{
            dp[i] = max(P[i]+dp[i+T[i]], dp[i+1]);
        }
    }
    
    cout << dp[1] << "\n";
    
    return 0;
}
