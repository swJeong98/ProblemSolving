/* BOJ 11052 카드 구매하기 - 2022.06.27 */
#include <bits/stdc++.h>
using namespace std;

int A[1005];
int dp[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    /*Initialization*/
    for(int i=0;i<1005;i++) fill(dp[i],dp[i]+1005,-1);
    for(int i=0;i<1005;i++) dp[i][0] = 0;
    /*dp*/
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i == 1) dp[i][j] = (A[i] * j);
            else{
                dp[i][j] = dp[i-1][j];
                if(j-i >= 0) dp[i][j] = max(dp[i][j], dp[i][j-i] + A[i]);
            }
        }
    }
    cout<<dp[N][N];
    return 0;
}