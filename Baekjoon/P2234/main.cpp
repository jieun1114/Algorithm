//
//  main.cpp
//  P2234
//
//  Created by 김지은 on 2020/11/06.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int brick[50][50];
bool visit[50][50];
int max_size = 0;
int room;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

struct path{
    int x,y;
};

void bfs(int i, int j){
    
    
    queue<path> q;
    q.push({i,j});
    visit[i][j] = true;
    room = 1;
    
    while (!q.empty()) {
        
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for (int i=0; i<4; i++) {
            if(!(brick[x][y]&(1<<i))){ // 벽이 없을 때
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visit[nx][ny]){
                    room++;
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    max_size = max(max_size,room);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    cin >> m >> n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> brick[i][j];
        }
    }
    
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(!visit[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n" << max_size << "\n";
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<4; k++) {
                if(brick[i][j]&(1<<k)){ // 벽이 있을때
                    memset(visit,false, sizeof(visit));
                    brick[i][j] -= (1<<k);
                    bfs(i,j);
                    brick[i][j] += (1<<k);
                }
            }
        }
    }
    
    
    cout << max_size << "\n";
    
    return 0;
}
