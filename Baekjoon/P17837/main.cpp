//
//  main.cpp
//  P17837
//
//  Created by 김지은 on 2020/10/16.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N,K;
int answer = 0;
int chess[12][12];
vector<int> v[12][12];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};


struct Dolls{
    int x,y,dir;
};

Dolls doll[11];

bool go(int num, int x, int y, int nx, int ny, int col){
    
    int start = 0;
    for (int i=0; i<v[x][y].size(); i++) {
        if(v[x][y][i]==num){
            start = i;
            break;
        }
    }
    
    if(col==1)
        reverse(v[x][y].begin()+start,v[x][y].end());
    
    for (int j=start; j<v[x][y].size(); j++) {
        v[nx][ny].push_back(v[x][y][j]);
        doll[v[x][y][j]].x = nx;
        doll[v[x][y][j]].y = ny;
    }
    v[x][y].erase(v[x][y].begin()+start, v[x][y].end());
    
    if(v[nx][ny].size()>=4)
        return false;
    
    return true;
    
}

void move(int cnt){
    
    if(cnt>1000){
        answer = -1;
        return;
    }
    
    bool check = true;
    
    for(int i=1; i<=K; i++){
        
        int x = doll[i].x;
        int y = doll[i].y;
        int dir = doll[i].dir;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if((nx<0 || nx>=N || ny<0 || ny>=N) || chess[nx][ny]==2){
            
            dir = dir&1 ? dir+1 : dir-1;
            doll[i].dir = dir;
            nx = x + dx[dir];
            ny = y + dy[dir];
            
            if(nx>=0 && nx<N && ny>=0 && ny<N && chess[nx][ny]!=2){
                if(chess[nx][ny]==0){
                    if(!go(i,x,y,nx,ny,0))
                        check = false;
                }else{
                    if(!go(i,x,y,nx,ny,1))
                        check = false;
                }
            }
        }
        else if(chess[nx][ny]==0){ // 흰
            if(!go(i,x,y,nx,ny,0))
                check = false;
        }else if(chess[nx][ny]==1){ // 빨강
            if(!go(i,x,y,nx,ny,1))
                check = false;
        }
        
        if(!check){
            answer = cnt;
            return;
        }
    }
   
    move(cnt+1);
    
}



int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> chess[i][j];
        }
    }
    
    for (int i=1; i<=K; i++) {
        int x,y,d;
        cin >> x >> y >> d;
        doll[i].x = x-1;
        doll[i].y = y-1;
        doll[i].dir = d;
        v[doll[i].x][doll[i].y].push_back(i);
    }
   
    move(1);
    cout << answer << "\n";
    
    return 0;
    
}
