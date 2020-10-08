//
//  main.cpp
//  P15663
//
//  Created by 김지은 on 2020/10/08.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
bool visit[9];
int answer[9];
int num[9];

void dfs(int idx, int cnt){
    
    answer[cnt] = num[idx];
    if(cnt==M){
        for (int i=1; i<=M; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    visit[idx] = true;
    int prev = -1;
    for (int i=0; i<N; i++) {
        if(!visit[i] && num[i]!=prev){
            dfs(i,cnt+1);
            visit[i] = false;
            prev = num[i];
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;
    
   
    
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }
    
    sort(num, num+N);
    vector<int> v;
    
    int prev = -1;
    for (int i=0; i<N; i++) {
        if(num[i]!=prev){
            dfs(i,1);
            visit[i] = false;
            prev = num[i];
        }
    }

    return 0;
}

