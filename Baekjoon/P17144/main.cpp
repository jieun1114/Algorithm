//
//  main.cpp
//  P17144
//
//  Created by 김지은 on 2020/09/19.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int R, C;
int dust[51][51];
int tmp[51][51];
vector<int> cleaner;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int clean(int time){
    
    for (int t=0; t<time; t++) {
        // 1. 미세먼지 확산
        memset(tmp, 0, sizeof(tmp));
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if(dust[i][j]>0){
                    int nx,ny;
                    int amount = dust[i][j]/5;
                    for (int k=0; k<4; k++) {
                        nx = i + dx[k];
                        ny = j + dy[k];
                        
                        if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
                        if(dust[nx][ny]==-1) continue;
                        tmp[nx][ny] += amount;
                        dust[i][j] -= amount;
                    }
                }
            }
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if(dust[i][j]!=-1)
                    dust[i][j] += tmp[i][j];
            }
        }
        
        // 2. 공기청정기 작동
        int ux = cleaner[0];
        int dx = cleaner[1];
        
        for (int i=ux-2; i>=0; i--)
            dust[i+1][0] = dust[i][0];
        for (int i=1; i<C; i++)
            dust[0][i-1] = dust[0][i];
        for (int i=1; i<=ux; i++)
            dust[i-1][C-1] = dust[i][C-1];
        for (int i=C-2; i>=1; i--)
            dust[ux][i+1] = dust[ux][i];
        dust[ux][1] = 0;
        
        for (int i=dx+2; i<R; i++)
            dust[i-1][0] = dust[i][0];
        for (int i=1; i<C; i++)
            dust[R-1][i-1] = dust[R-1][i];
        for (int i=R-2; i>=dx; i--)
            dust[i+1][C-1] = dust[i][C-1];
        for (int i=C-2; i>=1; i--)
            dust[dx][i+1] = dust[dx][i];
        dust[dx][1] = 0;
        
    }
    
    // 총 미세먼지 양
    int cnt = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if(dust[i][j]>0)
                cnt += dust[i][j];
        }
    }
    return cnt;
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int T;
    cin >> R >> C >> T;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> dust[i][j];
            if(dust[i][j]==-1)
                cleaner.push_back(i);
        }
    }
    
    cout << clean(T) << "\n";

    return 0;
}
