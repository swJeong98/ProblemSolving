/*BOJ 6549 히스토그램에서 가장 큰 직사각형 - 2022.03.25*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while(1){
        int N; cin>>N;
        if(N==0) break;
        stack<pair<int,int>> st;
        long long ans = 0;
        for(int i=0;i<N;i++){
            int h; cin>>h;
            int left = i;
            while(!st.empty() && st.top().first >= h){
                long long tmp = 1LL * (i-st.top().second) * (st.top().first);
                ans = max(ans,tmp);
                left = st.top().second; st.pop();
            }
            st.push({h,left});
        }
        //반드시 st.top().first가 마지막 것 보다 낮은 경우만 계산
        while(!st.empty()){
            long long tmp = 1LL* (N-st.top().second) * st.top().first;
            ans = max(ans,tmp);
            st.pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
