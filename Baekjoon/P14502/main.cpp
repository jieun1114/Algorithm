//
//  main.cpp
//  P14502
//
//  Created by 김지은 on 2020/10/12.
//  Copyright © 2020 김지은. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N,M;
int MAP[8][8];
int tmp[8][8];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visit[8][8];
bool check[8][8];
int answer = 0;

int safe(){
    
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if(tmp[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}

void dfs(int x, int y){
    
    check[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(!check[nx][ny] && tmp[nx][ny]==0){
                tmp[nx][ny] = 2;
                dfs(nx,ny);
            }
        }
    }
}

void install(int wall){
    
    if(wall==3){
        memset(check,false,sizeof(check));
        copy(&MAP[0][0],&MAP[0][0]+8*8,&tmp[0][0]);
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if(!check[i][j] && tmp[i][j]==2)
                    dfs(i,j);
            }
        }
        answer = max(answer,safe());
        return;
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if(!visit[i][j] && MAP[i][j]==0){
                MAP[i][j] = 1;
                visit[i][j] = true;
                install(wall+1);
                MAP[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> MAP[i][j];
        }
    }
    
    memset(visit,false,sizeof(visit));
    install(0);
    
    cout << answer << "\n";
    return 0;
}
