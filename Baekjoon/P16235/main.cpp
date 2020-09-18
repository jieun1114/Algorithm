//
//  main.cpp
//  P16235
//
//  Created by 김지은 on 2020/09/18.
//  Copyright © 2020 김지은. All rights reserved.
//

// 나무 재테크 - 시뮬레이션
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int food[11][11];
int A[11][11]; // 겨울마다 제공되는 양분
int N, M, K;
vector<pair<int,int>> tree[11][11]; // (나이, 살아있는지 여부)
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void spring(){
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(!tree[i][j].empty()){
                for (int k=0; k<tree[i][j].size(); k++) {
                    if(tree[i][j][k].first <=A[i][j]){
                        A[i][j] -= tree[i][j][k].first;
                        tree[i][j][k].first++;
                        //cout << i << j << " " << tree[i][j][k].first << "\n";
                    }else{
                        tree[i][j][k].second = 0; // 나무 죽음
                    }
                }
            }
        }
    }
}

void summer(){
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(!tree[i][j].empty()){
                int idx = -1; // 죽은 나무들 중 첫번쨰 인덱스
                for (int k=0; k<tree[i][j].size(); k++) {
                    if(tree[i][j][k].second==0){
                        idx = k;
                        break;
                    }
                }
                if(idx==-1) continue;
                for (int k=tree[i][j].size()-1; k>=idx; k--) {
                    A[i][j] += tree[i][j][k].first/2; // 죽은 나무들 양분으로
                    tree[i][j].pop_back(); // 죽은 나무 삭제
                }
            }
        }
    }
    
    
}

void fall(){
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(!tree[i][j].empty()){
                for (int k=0; k<tree[i][j].size(); k++) {
                    if(tree[i][j][k].first % 5 == 0){
                        int nx, ny;
                        for (int p=0; p<8; p++) {
                            nx = i + dx[p];
                            ny = j + dy[p];
                            if(nx<1 || nx>N || ny<1 || ny>N) continue;
                            tree[nx][ny].push_back(make_pair(1,1));
                        }
                    }
                }
            }
        }
    }
}

void winter(){
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            A[i][j] += food[i][j];
        }
    }
    
}

int alive(){
    
    int cnt = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cnt += tree[i][j].size();
        }
    }
    
    return cnt;
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    cin >> N >> M >> K;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> food[i][j];
        }
    }
    
    int x, y, z;
    for (int i=0; i<M; i++) {
        cin >> x >> y >> z;
        tree[x][y].push_back(make_pair(z, 1));
    }
    
    fill(&A[0][0],&A[N][N+1],5); // 초기 양분 5
    
    
    for(int k=0; k<K; k++){
        
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if(!tree[i][j].empty()){
                    sort(tree[i][j].begin(),tree[i][j].end()); // 나이 정렬
                }
            }
        }
        
        spring();
        summer();
        fall();
        winter();
    }
    
    
    cout << alive() << "\n";
    
    
    return 0;
}
