//
//  main.cpp
//  P1525
//
//  Created by 김지은 on 2020/11/17.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
int puzzle[3][3];
int answer = -1;
map<string,bool> m;

struct path{
    string s;
    int idx, cnt;
};

void bfs(string s, int idx){
    
    queue<path> q;
    q.push({s,idx,0});
    m[s] = true;
    
    while (!q.empty()) {
        
        string str = q.front().s;
        int k = q.front().idx;
        int cnt = q.front().cnt;
        
        q.pop();
        
        if(str=="123456789"){
            answer = cnt;
            break;
        }
        
        string tmp;
        
        if(k-3>=0){
            tmp = str;
            swap(tmp[k],tmp[k-3]);
            if(!m.count(tmp)){
                q.push({tmp,k-3,cnt+1});
                m[tmp] = true;
            }
        }
        
        if(k+3<9){
            tmp = str;
            swap(tmp[k],tmp[k+3]);
            if(!m.count(tmp)){
                q.push({tmp,k+3,cnt+1});
                m[tmp] = true;
            }
        }
        
        if(k==0 || k==1 || k==4 || k==7 || k==8){
            if(k-1>=0){
                tmp = str;
                swap(tmp[k],tmp[k-1]);
                if(!m.count(tmp)){
                    q.push({tmp,k-1,cnt+1});
                    m[tmp] = true;
                }
            }
            
            if(k+1<9){
                tmp = str;
                swap(tmp[k],tmp[k+1]);
                if(!m.count(tmp)){
                    q.push({tmp,k+1,cnt+1});
                    m[tmp] = true;
                }
            }
        }
        else if(k==2 || k==5){
            tmp = str;
            swap(tmp[k],tmp[k-1]);
            if(!m.count(tmp)){
                q.push({tmp,k-1,cnt+1});
                m[tmp] = true;
            }
        }else{
            tmp = str;
            swap(tmp[k],tmp[k+1]);
            if(!m.count(tmp)){
                q.push({tmp,k+1,cnt+1});
                m[tmp] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
   
    string s = "";
    int idx = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> puzzle[i][j];
            if(puzzle[i][j]==0){
                s += '9';
                idx = i*3+j;
            }
            else
                s += to_string(puzzle[i][j]);
        }
    }
    
    bfs(s,idx);
    
    cout << answer << "\n";
    
    return 0;
}
