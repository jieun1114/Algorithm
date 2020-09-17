//
//  main.cpp
//  P16918
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

int R, C, N;
char bomb[201][201];
int sec[201][201];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

using namespace std;

void bomber(int t){
    
    if(t&1){
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if(sec[i][j]==2 && bomb[i][j]=='O'){
                    bomb[i][j] = '.';
                    sec[i][j] = 0;
                    int nx, ny;
                    for (int k=0; k<4; k++) {
                        nx = i + dx[k];
                        ny = j + dy[k];
                        if(nx<0 || nx>=R || ny<0 || ny>=C || bomb[nx][ny]=='.') continue;
                        if(sec[nx][ny]==2)
                            continue;
                        bomb[nx][ny] = '.';
                        sec[nx][ny] = 0;
                    }
                }else if(bomb[i][j]=='O')
                    sec[i][j]++;
            }
        }
    }
    else{
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if(bomb[i][j]=='.'){
                    bomb[i][j] = 'O';
                }else
                    sec[i][j]++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> R >> C >> N;
    
    string str;
    for (int i=0; i<R; i++) {
        cin >> str;
        for (int j=0; j<C; j++) {
            bomb[i][j] = str[j];
            if(bomb[i][j]=='O')
                sec[i][j] = 1;
        }
    }
    
    for(int i=2; i<=N; i++){
        bomber(i);
    }
        
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << bomb[i][j];
        }
        cout << "\n";
    }
    
    
    return 0;
}
