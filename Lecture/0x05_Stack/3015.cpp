/* BOJ 3015 오아시스 재결합 - 2022.05.14 */
#include <bits/stdc++.h>
using namespace std;

int A[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    stack<pair<int,int>> st;
    long long ans = 0;
    for(int i=0;i<N;i++){
        int cnt = 1;
        bool escape = false;
        while(!st.empty()){
            int cur = st.top().first, w = st.top().second;
            if(cur < A[i]){
                ans += w;
            }
            else if(cur == A[i]){
                ans += w;
                cnt += w;
            }
            else{
                break;
            }
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push({A[i],cnt});
    }
    cout<<ans;
}
