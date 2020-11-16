//
//  main.cpp
//  P12869
//
//  Created by 김지은 on 2020/11/16.
//  Copyright © 2020 김지은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int answer = 987654321;
bool check[61][61][61];
int N;

void attack(int a, int b, int c, int cnt){
    
    if(a<0) a=0;
    if(b<0) b=0;
    if(c<0) c=0;
    
    if(a==0 && b==0 && c==0){
        answer = min(answer,cnt);
        return;
    }
    
    if(check[a][b][c])
        return;
    
    check[a][b][c] = true;
   
    if(a>0 && b>0 && c>0){
        attack(a-9,b-3,c-1,cnt+1);
        attack(a-3,b-9,c-1,cnt+1);
        attack(a-1,b-3,c-9,cnt+1);
        attack(a-3,b-1,c-9,cnt+1);
        attack(a-1,b-9,c-3,cnt+1);
        attack(a-9,b-1,c-3,cnt+1);
    }else if(a>0 && b>0){
        attack(a-9,b-3,c,cnt+1);
        attack(a-3,b-9,c,cnt+1);
    }else if(a>0 && c>0){
        attack(a-9,b,c-3,cnt+1);
        attack(a-3,b,c-9,cnt+1);
    }else if(b>0 && c>0){
        attack(a,b-9,c-3,cnt+1);
        attack(a,b-3,c-9,cnt+1);
    }else if(a>0){
        attack(a-9,b,c,cnt+1);
    }else if(b>0){
        attack(a,b-9,c,cnt+1);
    }else
        attack(a,b,c-9,cnt+1);
    
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    cin >> N;
    int scv[3] = {0,};
    
    for (int i=0; i<N; i++) {
        cin >> scv[i];
    }
    
    attack(scv[0],scv[1],scv[2],0);
    cout << answer << "\n";
    return 0;
}
