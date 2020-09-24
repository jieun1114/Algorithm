//
//  main.cpp
//  P1543
//
//  Created by 김지은 on 2020/09/24.
//  Copyright © 2020 김지은. All rights reserved.
//

// 문서 검색 - 그리디
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    string doc, word;
    getline(cin, doc);
    getline(cin, word);
    
    int answer = 0;
    int idx = 0;
    while (idx <= doc.size()-word.size()) {
        if (doc.find(word,idx)!=string::npos) {
            answer++;
            idx = doc.find(word,idx) + word.size();
        }
        else
            break;
    }
    cout << answer << "\n";
    
    return 0;
}

