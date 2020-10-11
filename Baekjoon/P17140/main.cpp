//
//  main.cpp
//  P17140
//
//  Created by 김지은 on 2020/10/11.
//  Copyright © 2020 김지은. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int r,c,k;
vector<vector<int>> A;
int row = 3, col = 3;
int max_size = 0;
map<int,int> m;

bool cmp(int a, int b){
    
    if(m[a]==m[b])
        return a < b;
    return m[a] < m[b];
}

vector<int> sorting(vector<int> v){
    
    vector<int> result;
    vector<int> number;
    m.clear();
    
    for(int num : v){
        if(num==0) continue;
        if(m.count(num)==0)
            number.push_back(num);
        m[num]++;
    }
    
    if(number.size()==0)
        return v;
    
    sort(number.begin(),number.end(),cmp);
    for(int num : number){
        result.push_back(num);
        result.push_back(m[num]);
        if(result.size()==100)
            break;
    }
    max_size = max(max_size, (int)result.size());
    
    return result;
}


int sortArr(){
    
    int time = 0;
    
    while (1) {
        
        if((row>=r && col>=c && A[r-1][c-1]==k) || time>100)
            break;
        
        time++;
        max_size = 0;
        
        if(row>=col){ // r 연산
            for (int i=0; i<row; i++)
                A[i] = sorting(A[i]);
            
            for (int i=0; i<row; i++){
                while(A[i].size()<max_size){
                    A[i].push_back(0);
                }
            }
            col = max_size;
        }else{ // c 연산
            vector<vector<int>> vc;
            for (int i=0; i<col; i++) {
                vector<int> tmp;
                for (int j=0; j<row; j++) {
                    tmp.push_back(A[j][i]);
                }
                vc.push_back(sorting(tmp));
            }
            for (int i=0; i<vc.size(); i++){
                while(vc[i].size()<max_size){
                    vc[i].push_back(0);
                }
            }
        
            A.clear();
            for (int i=0; i<max_size; i++) {
                for (int j=0; j<max_size; j++) {
                    vector<int> tmp;
                    for (int l=0; l<col; l++)
                        tmp.push_back(vc[l][j]);
                    A.push_back(tmp);
                }
            }
            row = max_size;
        }
    }
    return time;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    
    cin >> r >> c >> k;
    
    for (int i=0; i<3; i++) {
        vector<int> tmp;
        for (int j=0; j<3; j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        A.push_back(tmp);
    }
    int answer = sortArr();
    
    if(answer>100)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
    
    return 0;
}
