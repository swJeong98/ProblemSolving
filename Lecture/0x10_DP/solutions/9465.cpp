/* BOJ 9465 스티커 - 2022.09.05 */
#include <bits/stdc++.h>
using namespace std;

int dp[100005][3], A[2][100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        for(int r=0;r<2;r++){
            for(int i=0;i<N;i++) cin>>A[r][i];
        }

        for(int i=0;i<N+1;i++) fill(dp[i], dp[i]+3, 0);
        dp[0][0] = 0, dp[0][1] = A[0][0], dp[0][2] = A[1][0];
        for(int i=1;i<N;i++){
            dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + A[0][i];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + A[1][i];
        }
        cout<<max({dp[N-1][0], dp[N-1][1], dp[N-1][2]})<<'\n';
    }
    return 0;
}