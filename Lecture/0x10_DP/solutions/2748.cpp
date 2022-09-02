/* BOJ 2748 피보나치 수 2 - 2022.09.02 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[95];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    dp[0] = 0, dp[1] = 1;
    for(int i=2;i<=90;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[N];
    return 0;
}