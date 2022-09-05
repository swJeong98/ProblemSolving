/* BOJ 1788 피보나치 수의 확장 - 2022.09.05 */
#include <bits/stdc++.h>
using namespace std;

int dp[2000005];
const int MOD = (int)1e9;
const int T = (int)1e6;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    dp[0+T] = 0, dp[1+T] = 1;
    for(int i=2;i<=T;i++) dp[i+T] = (dp[i-1+T] + dp[i-2+T]) % MOD;
    for(int i=-1;i>=-T;i--) dp[i+T] = (dp[i+2+T] - dp[i+1+T]) % MOD;

    int N; cin>>N;
    if(dp[N+T] > 0) cout<<1<<'\n';
    else if(dp[N+T] == 0) cout<<0<<'\n';
    else cout<<-1<<'\n';

    cout<<abs(dp[N+T]);
    return 0;
}