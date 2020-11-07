//
//  main.cpp
//  P1922
//
//  Created by 김지은 on 2020/11/07.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

int parent[MAX+1];
int N, M;


int getParent(int x){
    if(parent[x]==x)
        return x; // 최종 부모 노드
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b){ // 두 노드의 부모노드 일치시킴
    a = getParent(a);
    b = getParent(b);

    if(a<b){ // 작은 값을 부모 노드로 선택
        parent[b] = a;
        return a;
    }else{
        parent[a] = b;
        return b;
    }
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a==b)
        return true;
    return false;
}
       


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    vector<pair<int,pair<int,int>>> v;
    
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if(a!=b)
            v.push_back({d,{a,b}});
    }
    
    sort(v.begin(),v.end());
  
    
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    int sum = 0;
    for (int i=0; i<v.size(); i++) {
        if(!findParent(v[i].second.first, v[i].second.second)){
            sum += v[i].first;
            unionParent(v[i].second.first, v[i].second.second);
        }
    }
    
    cout << sum << "\n";
    
    
    return 0;
}
