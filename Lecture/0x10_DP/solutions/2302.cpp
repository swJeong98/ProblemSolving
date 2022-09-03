/* BOJ 2302 극장 좌석 - 2022.09.03 */
#include <bits/stdc++.h>
using namespace std;

int dp[45], vip[45];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for(int i=3;i<=N;i++) dp[i] = dp[i-1] + dp[i-2];

    int M; cin>>M;
    for(int i=0;i<M;i++) cin>>vip[i];

    int st = 1, ans = 1;
    for(int i=0;i<M;i++){
        ans *= dp[vip[i] - st];
        st = vip[i] + 1;
    }
    ans *= dp[N - st+1];
    cout<<ans;
    return 0;
}
