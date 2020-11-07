//
//  main.cpp
//  P4386
//
//  Created by 김지은 on 2020/11/08.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

int parent[MAX+1];
int N;

int getParent(int x){
    if(parent[x]==x)
        return x;
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b){ // 두 노드의 부모노드 일치시킴
    a = getParent(a);
    b = getParent(b);
    
    if(a<b){
        parent[b] = a;
        return a;
    }
    else{
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
    
    vector<pair<double,pair<int,int>>> v;
    vector<pair<double,double>> stars;
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        double x, y;
        cin >> x >> y;
        stars.push_back({x,y});
    }
    
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            double dist = sqrt(pow(abs(stars[i].first-stars[j].first),2) + pow(abs(stars[i].second-stars[j].second),2));
            v.push_back({dist,{i,j}});
        }
    }
    
    sort(v.begin(),v.end());
  
    
    for(int i=0; i<N; i++){
        parent[i] = i;
    }

    double sum = 0;
    for (int i=0; i<v.size(); i++) {
        if(!findParent(v[i].second.first, v[i].second.second)){
            sum += v[i].first;
            unionParent(v[i].second.first, v[i].second.second);
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << sum << "\n";
    
    return 0;
}
