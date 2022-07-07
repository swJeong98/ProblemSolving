/*BOJ 17298 오큰수 - 2022.03.24*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ans(1000005);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N; cin>>N;
    stack<pair<int,int>> st;
    for(int i=0;i<N;i++){
        int num; cin>>num;
        while(!st.empty() && st.top().first < num){
            ans[st.top().second] = num;
            st.pop();
        }
        st.push({num,i});
    }
    while(!st.empty()){
        ans[st.top().second] = -1;
        st.pop();
    }
    for(int i=0;i<N;i++) cout<<ans[i]<<' ';
    return 0;
}