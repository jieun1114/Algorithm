//
//  main.cpp
//  P1753
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

#define MAX 20000
#define INF 1e9

using namespace std;

int dist[MAX+1];
vector<pair<int,int>> graph[MAX+1];

void dijkstra(int start){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start]=0;
    
    while(!pq.empty()){

        int curr = pq.top().second;
                 
        pq.pop();
            
        for(int i=0; i<graph[curr].size(); i++){

            int next = graph[curr][i].first;
            int cost = graph[curr][i].second;
            
            if(dist[next] > dist[curr] + cost){
                dist[next] = dist[curr]+ cost;
                pq.push({dist[next],next});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int v,e,k;
    cin >> v >> e >> k;
    
    for (int i=0; i<e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    
    fill(dist,dist+v+1,INF);
    dijkstra(k);
    
    for (int i=1; i<=v; i++) {
        if(dist[i]==INF)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }
    
    return 0;
}
