/* BOJ 11057 오르막 수 - 2022.05.09 */
#include <bits/stdc++.h>
using namespace std;

long long dp[1005][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<=9;i++) dp[1][i] = 1;
    
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= (long long)10007;
            }
        }
    }

    long long ans = 0;
    for(int i=0;i<=9;i++){
        ans += dp[N][i];
        ans %= (long long)10007;
    }
    cout<<ans;
}