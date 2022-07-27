/* BOJ 9461 파도반 수열 - 2022.04.19 */
#include <bits/stdc++.h>
using namespace std;

long long dp[105];

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    dp[1]=dp[2]=dp[3]=1;
    for(int i=4; i<=100; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        cout<<dp[N]<<'\n';
    }
    return 0;
}