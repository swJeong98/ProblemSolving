/*BOJ 10844번 쉬운 계단수 - 2022.03.05*/
#include <iostream>
#define MOD 1000000000
using namespace std;

long long dp[105][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=1;i<=9;i++) dp[1][i] = 1;
    
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            if(j==0) {
                dp[i][j] = dp[i-1][j+1] % MOD; continue;
            }
            dp[i][j] = (dp[i-1][j-1] % MOD) + (dp[i-1][j+1] % MOD);
        }
    }
    
    long long ans = 0;
    for(int i=0;i<=9;i++){
        ans += (dp[N][i]);
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}