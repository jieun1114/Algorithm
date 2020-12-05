//
//  main.cpp
//  P1068
//
//  Created by 김지은 on 2020/12/05.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;
vector<int> L[51];
bool erase[51];

void deleteNode(int cur){
    
    erase[cur] = true;
    
    while (!L[cur].empty()) {
        deleteNode(L[cur].back());
        L[cur].pop_back();
    }
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    int p, d;
    for (int i=0; i<N; i++) {
        cin >> p;
        if(p!=-1)
            L[p].push_back(i);
    }
    
    cin >> d;
    deleteNode(d);
    
    int answer = 0;
    for (int i=0; i<N; i++) {
        if(erase[i])
            continue;
        if(L[i].size()==0 || (L[i].size()==1 && L[i][0]==d))
            answer++;
    }
    
    cout << answer << "\n";
    return 0;
}
