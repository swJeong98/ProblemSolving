/* BOJ 1904 01타일 - 2022.09.05 */
#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
const int MOD = 15746;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;

    dp[1] = 1, dp[2] = 2;
    for(int i=3;i<=1000000;i++) dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    cout<<dp[N];
    return 0;
}