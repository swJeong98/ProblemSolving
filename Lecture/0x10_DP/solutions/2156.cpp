/* BOJ 2156 포도주 시식 - 2022.09.02 */
#include <bits/stdc++.h>
using namespace std;

int dp[10005][2], A[10005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<=N;++i) cin>>A[i];

    dp[1][0] = A[1]; dp[1][1] = 0;
    for(int i=2;i<=N;i++){
        int tmp = 0;
        for(int k=1;k<=i-2;k++){
            tmp = max({tmp, dp[k][0], dp[k][1]});
        }
        dp[i][0] = tmp + A[i];
        dp[i][1] = dp[i-1][0] + A[i];
    }

    int mx = 0;
    for(int i=1;i<=N;i++){
        mx = max({mx, dp[i][0], dp[i][1]});
    }
    cout<<mx;
    return 0;
}