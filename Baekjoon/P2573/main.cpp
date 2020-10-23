//
//  main.cpp
//  P2573
//
//  Created by 김지은 on 2020/10/22.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int ice[300][300];
int tmp[300][300];
bool visit[300][300];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M;


void dfs(int i, int j){
    
    visit[i][j] = true;
    
    for (int k=0; k<4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx>=1 && nx<N-1 && ny>=1 && ny<M-1 && ice[nx][ny]!=0 && !visit[nx][ny]){
            dfs(nx,ny);
        }
    }
    
}


bool lump(){
    
    memset(visit,false,sizeof(visit));
    int cnt = 0;
    for (int i=1; i<N-1; i++) {
        for (int j=1; j<M-1; j++) {
            if(ice[i][j]!=0 && !visit[i][j]){
                dfs(i,j);
                cnt++;
                if(cnt>1)
                    return true;
            }
        }
    }
    return false;
}

bool zero(){
    
    bool flag = true;
    for (int i=1; i<N-1; i++) {
        for (int j=1; j<M-1; j++) {
            if(ice[i][j]!=0){
                flag = false;
                break;
            }
        }
    }
    
    return flag;
}

void melting(){
    
    copy(&ice[0][0],&ice[0][0]+300*300,&tmp[0][0]);
    
    for (int i=1; i<N-1; i++) {
        for (int j=1; j<M-1; j++) {
            if(ice[i][j]!=0){
                int cnt = 0;
                for (int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && ice[nx][ny]==0)
                        cnt++;
                }
                if(cnt>ice[i][j])
                    tmp[i][j] = 0;
                else
                    tmp[i][j] = ice[i][j]-cnt;
            }
        }
    }
    
    copy(&tmp[0][0],&tmp[0][0]+300*300,&ice[0][0]);
    
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    memset(ice,0,sizeof(ice));
    memset(tmp,0,sizeof(tmp));
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> ice[i][j];
        }
    }
    
    int answer = 0;
    
    while (!lump()) { // 한 덩어리 일때
        melting();
        if(zero()){
            cout << 0 << "\n";
            return 0;
        }
        answer++;
    }
    
    cout << answer << "\n";
    
    
    return 0;
}
