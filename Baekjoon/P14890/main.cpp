//
//  main.cpp
//  P14890
//
//  Created by 김지은 on 2020/10/14.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, L;
int MAP[100][100];
bool visit[100];

int answer = 0;

void road(vector<int> v){
    
    //bool flag = true;
    memset(visit,false,sizeof(visit));
    for (int i=0; i<N-1; i++) {
        if(abs(v[i]-v[i+1])>1)
            return;
        
        if(v[i]==v[i+1])
            continue;
        
        if(v[i]>v[i+1]){
            if(i+L>=N)
                return;
            
            for (int k=i+1; k<i+1+L; k++) {
                if(v[k]!=v[i]-1)
                    return;
            }
        
            for (int k=i+1; k<i+1+L; k++)
                visit[k] = true;
            i = i+L-1;
        }
        else{
            if(visit[i] || i+1-L<0)
                return;
            
            for (int k=i; k>=i+1-L; k--) {
                if(visit[k] || v[k]!=v[i])
                    return;
            }
            
            for (int k=i; k>=i+1-L; k--)
                visit[k] = true;
        }
    }
    
    answer++;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> MAP[i][j];
        }
    }
    
    for (int i=0; i<N; i++) { // 행
        vector<int> v;
        for (int j=0; j<N; j++) {
            v.push_back(MAP[i][j]);
        }
        road(v);
    }
    
    for (int i=0; i<N; i++) { // 열
        vector<int> v;
        for (int j=0; j<N; j++) {
            v.push_back(MAP[j][i]);
        }
        road(v);
    }
    
    cout << answer << "\n";
    return 0;
}
