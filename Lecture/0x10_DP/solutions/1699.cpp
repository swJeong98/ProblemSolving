/* BOJ 1699 제곱수의 합 - 2022.04.08 */
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dp[100005];

int main(void)
{
    FASTIO
    int N; cin>>N;
    dp[1] = 1;
    for(int i=2; i<=N; i++){
        int limit = (int)sqrt(double(i));
        int mn = 100005;
        for(int j=1; j<=limit; j++) 
            mn = min(mn, dp[i-(j*j)]);
        dp[i] = mn + 1;
    }
    cout<<dp[N];
    return 0;
}