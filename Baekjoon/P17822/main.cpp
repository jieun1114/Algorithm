//
//  main.cpp
//  P17822
//
//  Created by 김지은 on 2020/10/22.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, M, T;
deque<int> circle[51];
vector<pair<pair<int, int>, int>> turn;


void move(int i, int d, int k) {

    if (d == 0) { //시계방향
        for (int j = 0; j < k; j++)
        {
            circle[i].push_front(circle[i].back());
            circle[i].pop_back();
        }
    }
    else { // 반시계방향
        for (int j = 0; j < k; j++)
        {
            circle[i].push_back(circle[i].front());
            circle[i].pop_front();
        }
    }

}

void remove() {

    deque<int> tmp[51];
    
    for (int j = 1; j <= N; j++)
        tmp[j].assign(circle[j].begin(), circle[j].end());
    
    int cnt = 0;
    for (int i = 1; i <= N; i++) // 원판 안에서 인접한 수 제거
    {
        for (int j = 0; j < M; j++) {
            if (j == M - 1) {
                if (circle[i][j]!=-1 && circle[i][j] == circle[i][0]) {
                    tmp[i][0] = -1;
                    tmp[i][j] = -1;
                    cnt++;
                }
            }
            else if (circle[i][j] != -1 && circle[i][j] == circle[i][j + 1]) {
                tmp[i][j] = -1;
                tmp[i][j+1] = -1;
                cnt++;
            }
        }
    }

    for (int i = 1; i < N; i++) { // 인접한 원판끼리 비교

        for (int j = 0; j < M; j++) {
            if (circle[i][j] != -1 && circle[i][j] == circle[i + 1][j]) {
                tmp[i][j] = -1;
                tmp[i + 1][j] = -1;
                cnt++;
            }
        }
    }

    if (cnt == 0) { // 인접한 수 없는 경우
        int sum = 0;
        int count = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (circle[i][j] != -1) {
                    sum += circle[i][j];
                    count++;
                }
            }
        }
        double avg = (double)sum / count;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (circle[i][j] != -1) {
                    if (circle[i][j] > avg)
                        circle[i][j]--;
                    else if (circle[i][j] < avg)
                        circle[i][j]++;
                }
            }
        }
    }
    else {
        for (int j = 1; j <= N; j++)
            circle[j].assign(tmp[j].begin(), tmp[j].end());
    }

}

int result() {

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][j] != -1) {
                sum += circle[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> N >> M >> T; // 원판 크기 / 정수 개수/ 회전 횟수

    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            circle[i].push_back(a);
        }
    }

    for (int i = 0; i < T; i++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        turn.push_back({ { x,d }, k });
    
    }


    for (int i = 0; i < T; i++)
    {
        int x = turn[i].first.first;
        int d = turn[i].first.second;
        int k = turn[i].second;


        for (int j = 1; j <= N; j ++)
        {
            if (j%x == 0)
                move(j, d, k);
        }

        remove();
    }

    int answer = result();
    cout << answer << "\n";
    
    return 0;
}
