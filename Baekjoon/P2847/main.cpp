//
//  main.cpp
//  P2847
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
    int score[n];
    for (int i=0; i<n; i++) {
        cin >> score[i];
    }
    
    int cnt = 0;
    
    for (int i=n-2; i>=0; i--) {
        if(score[i]>=score[i+1]){
            cnt += score[i]-(score[i+1]-1);
            score[i] = score[i+1]-1;
        }
    }
    
    cout << cnt << "\n";
    return 0;

}
