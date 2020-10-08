//
//  main.cpp
//  P10026
//
//  Created by 김지은 on 2020/10/08.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 100
using namespace std;

int N;
char color[102][102];
bool visit[102][102];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void normal(int i, int j){
    
    visit[i][j] = true;
    char col = color[i][j];
    queue<pair<int,int>> q;
    q.push({i,j});
    
    while (!q.empty()) {
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<N && ny>=0 && ny<N && !visit[nx][ny]){
                if(color[nx][ny]==col){
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void blind(int i, int j){
    
    visit[i][j] = true;
    char col = color[i][j];
    queue<pair<int,int>> q;
    q.push({i,j});
    
    while (!q.empty()) {
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<N && ny>=0 && ny<N && !visit[nx][ny]){
                if(col=='B' && color[nx][ny]==col){
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }else if(col!='B' && color[nx][ny]!='B'){
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        for (int j=0; j<N; j++) {
            color[i][j] = str[j];
        }
    }
    
    memset(visit, false, sizeof(visit));
    int cnt1 = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if(!visit[i][j]){
                normal(i,j);
                cnt1++;
            }
        }
    }
    
    memset(visit, false, sizeof(visit));
    int cnt2 = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if(!visit[i][j]){
                blind(i,j);
                cnt2++;
            }
        }
    }
    
    cout << cnt1 << " " << cnt2 << "\n";
    
    
    return 0;
}
