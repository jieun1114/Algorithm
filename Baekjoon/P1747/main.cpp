//
//  main.cpp
//  P1747
//
//  Created by 김지은 on 2020/11/16.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1000000

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    bool prime[MAX+1];
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
    for (int i=2; i<=sqrt(MAX); i++) {
        if(prime[i]){
            for (int j=i+i; j<=MAX; j+=i) {
                prime[j] = false;
            }
        }
    }

    int num = N;
    while (1) {
        
        if(!prime[num]){
            num++;
            continue;
        }
        string str = to_string(num);
        bool flag = true;
        for (int i=0; i<str.size()/2; i++) {
            if(str[i]!=str[str.size()-i-1]){
                flag = false;
                break;
            }
        }
        if(flag)
            break;
        else
            num++;
    }
    
    cout << num << "\n";
    
    
    return 0;
}
