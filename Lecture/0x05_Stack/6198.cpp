/* BOJ 6198 옥상 정원 꾸미기 - 2022.05.14 */
#include <bits/stdc++.h>
using namespace std;

int A[80005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    
    stack<pair<int,int>> st;
    long long ans = 0;
    for(int i=0;i<N;i++){
        while(!st.empty() && st.top().first <= A[i]){
            ans += (i - st.top().second)-1;
            st.pop();
        }
        st.push({A[i], i});
    }

    while(!st.empty()){
        ans += (N-1 - (st.top().second));
        st.pop(); 
    }
    cout<<ans;
}
