#include <bits/stdc++.h>
using namespace std;

//각 상자 별 그룹 번호
int grp[105];

void makeGroup(const vector<int>& cards, int idx, int num) {
    
    bool vis[105] = {};
    while(!vis[idx]) {
        vis[idx] = true;
        grp[idx] = num;
        idx = cards[idx]-1;
    }
}

//그룹에 속한 원소 개수 판단
int grpSize(int num) {
    int ret = 0;
    for(int i=0; i<105; i++) {
        if(grp[i] == 0 || grp[i] != num) continue;
        ret += 1;
    }
    return ret;
}

int solution(vector<int> cards) {
    
    //그룹 만들기
    int cnt = 1;
    for(int i=0; i<cards.size(); i++) {
        if(grp[i]) continue;
        makeGroup(cards, i, cnt);
        cnt++;
    }
        
    //순회하면서 최고 점수 계산
    int answer = 0;
    bool mark[105] = {};
    for(int i=0; i<cards.size(); i++) {
        if(mark[grp[i]]) continue;
        mark[grp[i]] = true;
        
        int sz1 = grpSize(grp[i]);
        int sz2 = 0;
        for(int j=0; j<cards.size(); j++){
            if(grp[j] == grp[i]) continue;
            
            sz2 = grpSize(grp[j]);
            answer = max(answer, sz1 * sz2);
        }
    }
    
    //가능한 최고 점수를 담아서 리턴
    return answer;
}
