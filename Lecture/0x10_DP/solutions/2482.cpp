/**
 * BOJ 2482 색상환 - 2023.01.23
 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 3;

int N, K;
int dp[1005][1005];
int ans[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=0; i<=N; i++) dp[i][0] = 1;
    for(int i=1; i<=N; i++) dp[i][1] = i;

    for(int i=2; i<=N; i++) {
        for(int j=2; j<=i; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }

    for(int i=4; i<=N; i++) {
        for(int j=1; j<=(i/2); j++) {
            ans[i][j] = (dp[i-3][j-1] + dp[i-1][j]) % MOD;
        }
    }
    cout<<ans[N][K]<<'\n';
    return 0;
}