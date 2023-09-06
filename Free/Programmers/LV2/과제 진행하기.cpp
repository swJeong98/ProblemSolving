#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

//{과제 이름, playtime}이 저장되며 시작 시각이 배열의 인덱스
const int MAX = 1e6;
pair<string,int> A[MAX];

int convert(string time){
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    
    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    
    for(int i=0; i<plans.size(); i++) {
        string name = plans[i][0];
        string startTime = plans[i][1];
        string playtime = plans[i][2];
        
        A[convert(startTime)] = {name, stoi(playtime)};
    }
    
    stack<pair<string,int>> st;
    vector<string> ans;
    
    for(int i=0; i<MAX; i++) {
        if(A[i].Y == 0) {
            if(st.empty()) continue;
            
            st.top().Y -= 1;
            if(st.top().Y == 0) {
                ans.push_back(st.top().X);
                st.pop();
            }
            continue;
        }
        
        if(st.empty()) {
            st.push(A[i]);
        }else{
            st.top().Y -= 1;
            if(st.top().Y == 0) {
                ans.push_back(st.top().X);
                st.pop();
            }
            st.push(A[i]);          
        }
    }
    
    //과제를 끝낸 순서대로 "이름"을 담아 리턴
    return ans;
}
