//
//  main.cpp
//  P16234
//
//  Created by 김지은 on 2020/10/14.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, L, R;
int MAP[50][50];
bool visit[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int openDoor(int i, int j) {

    int sum = MAP[i][j];
    int cnt = 1;
    queue<pair<int, int>> q;
    visit[i][j] = true;
    q.push({ i,j });
    vector<pair<int, int>> v;
    v.push_back({ i,j });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {
                int diff = abs(MAP[x][y] - MAP[nx][ny]);
                
                if (diff >= L && diff <= R) {
                    sum += MAP[nx][ny];
                    cnt++;
                    visit[nx][ny] = true;
                    q.push({ nx,ny });
                    v.push_back({ nx,ny });
                }
            }
        }
    }

    if (cnt == 1) // 인구이동 없으면
        return 0;

    // 인구 이동 있으면
    int p = floor(sum / cnt);
    for (int i = 0; i < v.size(); i++) {
        MAP[v[i].first][v[i].second] = p;
    }

    return 1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }

    int answer = 0;

    while (1) {
        int cnt = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visit[i][j]) {
                    cnt += openDoor(i, j);
                }
            }
        }
        if (cnt == 0)
            break;

        answer++;
        
    }
    
    cout << answer << "\n";
    return 0;
}
