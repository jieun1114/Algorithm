//
//  main.cpp
//  P2512
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

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int N,M;
    cin >> N;
    int bud[10000];
    int sum = 0;
    
    for (int i=0; i<N; i++) {
        cin >> bud[i];
        sum += bud[i];
    }
    
    cin >> M;
    
    sort(bud, bud+N);
    int low = 1;
    int hi = bud[N-1];
    int answer = 0;
    int max_bud = 0;
    
    if(sum<=M){
        cout << hi << "\n";
        return 0;
    }
    
    while (low<=hi) {
        int mid = (low+hi)/2;
        
        int total = 0;
        for (int i=0; i<N; i++) {
            total += min(mid,bud[i]);
        }
        if(total>M){ // 예산 초과
            hi = mid-1;
        }else{
            if(total > max_bud){
                max_bud = total;
                answer = mid;
            }
            low = mid + 1;
        }
    }
    
    cout << answer << "\n";
    
    // 110 120 140 150
    
    return 0;
}
