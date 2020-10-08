//
//  main.cpp
//  P9663
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

int N;
int answer = 0;
void dfs(int i, int j, int cnt, bool queen[][15]){
    
    bool q[15][15];
    copy(&queen[0][0], &queen[0][0]+15*15, &q[0][0]);
    //cout << i << " " << j << " " << cnt << "\n";
    
    if(cnt==N){
        answer++;
        return;
    }
    
    for(int r=0; r<N; r++) // 세로
        q[r][j] = true;
    for(int c=0; c<N; c++) // 가로
        q[i][c] = true;
    
    int r = i;
    int c = j;
    while (r>0 && c>=0 && r<N && c<N-1) { // 대각선 위오
        q[--r][++c] = true;
    }
    r = i;
    c = j;
    while (r>=0 && c>=0 && r<N-1 && c<N-1) { // 대각선 아래오
        q[++r][++c] = true;
    }
    r = i;
    c = j;
    while (r>0 && c>0 && r<N && c<N) { // 대각선 위왼
        q[--r][--c] = true;
    }
    r = i;
    c = j;
    while (r>0 && c>=0 && r<N-1 && c<N) { // 대각선 아래왼
        q[++r][--c] = true;
    }
    
    
    
    for (int r=0; r<N; r++) {
        if(j+1<N && !q[r][j+1]){
            q[r][j+1] = true;
            dfs(r, j+1, cnt+1, q);
            q[r][j+1] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin >> N;
    
    bool queen[15][15];
    memset(queen, false, sizeof(queen));
    
    for (int i=0; i<N; i++) {
        dfs(i,0,1,queen);
    }
    
    cout << answer << "\n";
    return 0;
}
