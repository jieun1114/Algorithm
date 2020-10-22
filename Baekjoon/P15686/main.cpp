//
//  main.cpp
//  P15686
//
//  Created by 김지은 on 2020/10/22.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int city[50][50];
int dist[50][50];

void distance(int x, int y) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (city[i][j] == 1) {
                dist[i][j] = min(dist[i][j], abs(x - i) + abs(y - j));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int answer = 987654321;

    vector<pair<int, int>> chickens[13];
    int idx = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 2) {
                chickens[idx].push_back({i,j});
                idx++;
            }
        }
    }

    vector<int> sel(idx, 0); // 총 치킨집 개수
    for (int i = 0; i < M; i++)
        sel[i] = 1;
    
    sort(sel.begin(), sel.end());
    

    do {
    
        fill(&dist[0][0], &dist[49][50], 200);
        for (int i = 0; i < sel.size(); i++) {
            if (sel[i] == 1) {
                int x = chickens[i].front().first;
                int y = chickens[i].front().second;
                distance(x, y);
            }
        }

        int total = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (city[i][j] == 1) {
                    total += dist[i][j];
                }
            }
        }

        answer = min(answer, total);


    } while (next_permutation(sel.begin(), sel.end()));
     
    
    cout << answer << "\n";

    return 0;
}
