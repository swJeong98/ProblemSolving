#include <bits/stdc++.h>
using namespace std;

string types[] = {"diamond", "iron", "stone"};

int score[3][3] = {{1, 1, 1},
                 {5, 1, 1},
                 {25, 5, 1}};

int resolve(string type) {
    for(int i=0; i<3; i++) {
        if(type == types[i]) return i;
    }    
    
    //unreachable
    return -1;
}

int solution(vector<int> picks, vector<string> minerals) {
    vector<int> tools;
    for(int i=0; i<picks.size(); i++) {
        for(int j=0; j<picks[i]; j++) {
            tools.push_back(i);
        }
    }
    
    int ans = 1e8;
    int N = (int)minerals.size();
    int idx = 0;
    
    do{
        idx = 0;
        int sum = 0;
        
        for(int i=0; i<tools.size(); i++) {
            if(idx == N) break;
            for(int j=0; j<5; j++){
                if(idx == N) break;
                sum += score[tools[i]][resolve(minerals[idx++])];
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(tools.begin(), tools.end()));
    
    //최소한의 피로도를 리턴
    return ans;
}
