//
//  main.cpp
//  P2885
//
//  Created by 김지은 on 2020/09/24.
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
    //freopen("input.txt", "r", stdin);
    int k;
    cin >> k;
    
    int min_size = 0;
    for (int i=0; i<=20; i++) {
        if(pow(2,i)==k){
            min_size = k;
            break;
        }
        else if(k>pow(2,i) && k<pow(2,i+1)){
            min_size = pow(2,i+1);
            break;
        }
    }
    
    int choc = min_size;
    int cnt = 0;
    int now = 0;
    
    if(choc != k){
        while (choc>0) {
            if(now+choc/2 <= k)
                now += choc/2;
            choc /= 2;
            cnt++;
            if(now==k)
                break;
        }
    }
    
    cout << min_size << " " << cnt << "\n";
    return 0;
}
