//
//  main.cpp
//  P4796
//
//  Created by 김지은 on 2020/12/19.
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
    
    int i = 1;
    int L, P, V;
    
    while (1) {
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0)
            break;
        
        int days = (V/P) * L;
        days += min(L,V%P);
        cout << "Case " << i << ": " << days << "\n";
        i++;
    }
    
    return 0;

}
