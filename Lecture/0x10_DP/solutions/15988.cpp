/* BOJ 15988 1,2,3 더하기 3 - 2022.09.02 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000005];
const int MOD = 1e9 + 9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T; cin>>T;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    for(int i=4;i<=(int)1e6;i++){
        dp[i] = ( dp[i-1] + dp[i-2] + dp[i-3] ) % MOD;
    }

    while(T--){
        int x; cin>>x;
        cout<<dp[x]<<'\n';
    }
    return 0;
}