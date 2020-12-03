//
//  main.cpp
//  P0000
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
    
    int N, B;
    cin >> N >> B;
    
    int n = N;
    string str;
    

    if(B<=10){
        while (n!=0) {
            str += to_string(n%B);
            n /= B;
        }
    }else{
        while (n!=0) {
            if(n%B >= 10)
                str += n%B+55;
            else
                str += to_string(n%B);
            n /= B;
        }
    }
    
    reverse(str.begin(),str.end());
    
    cout << str << "\n";
    return 0;
}

