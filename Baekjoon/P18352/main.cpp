//
//  main.cpp
//  P18352
//
//  Created by 김지은 on 2020/09/26.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 300000
#define INF 1e9

using namespace std;

int dist[MAX+1];
vector<int> city[MAX+1];


void dijkstra(int start){
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(start);
    dist[start] = 0;
    
    while (!pq.empty()) {
        
        int cur = pq.top();;
        pq.pop();
        
        for (int i=0; i<city[cur].size(); i++) {
            int next = city[cur][i];
            if(dist[next] > dist[cur]+1){
                dist[next] = dist[cur] + 1;
                pq.push(next);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        city[a].push_back(b);
    }
    
    fill(dist,dist+N+1,INF);
    dijkstra(X);
    
    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(dist[i]==K){
            cout << i << "\n";
            cnt++;
        }
    }
    if(cnt==0)
        cout << -1 << "\n";
    
    return 0;
}
