//
//  main.cpp
//  P11779
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

#define MAX 1000
#define INF 1e9

using namespace std;

int dist[MAX+1];
int trace[MAX+1];
vector<pair<int,int>> graph[MAX+1];

void dijkstra(int start){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;
    trace[start] = 0;
    
    while(!pq.empty()){

        int curr = pq.top().second;
                 
        pq.pop();
            
        for(int i=0; i<graph[curr].size(); i++){

            int next = graph[curr][i].first;
            int cost = graph[curr][i].second;
            
            if(dist[next] > dist[curr] + cost){
                dist[next] = dist[curr]+ cost;
                pq.push({dist[next],next});
                trace[next] = curr;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int v,e;
    cin >> v >> e;
    
    for (int i=0; i<e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    int start, dest;
    cin >> start >> dest;
    
    fill(dist,dist+v+1,INF);
    dijkstra(start);
    
    int idx = dest;
    int cnt = 0;
    vector<int> tmp;
    tmp.push_back(dest);
    
    while (idx!=0) {
        tmp.push_back(trace[idx]);
        idx = trace[idx];
        cnt++;
    }
    
    cout << dist[dest] << "\n" << cnt << "\n";
    for (int i=tmp.size()-2; i>=0; i--) {
        cout << tmp[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
