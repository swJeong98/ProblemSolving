/* BOJ 2217 로프 - 2022.05.07 */
#include <bits/stdc++.h>
using namespace std;

int W[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>W[i];
    sort(W+1,W+N+1,greater<>());
    
    int ans = W[1];
    for(int i=2;i<=N;i++){
        ans = max(ans, W[i] * i);
    }
    cout<<ans;
}