/* BOJ 2579 계단 오르기  - 2022.07.27 */
#include <bits/stdc++.h>
using namespace std;

int A[305], dp[305][305];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
        
    /*Base Case*/
    for(int i=0;i<N+1;i++) dp[i][0] = 0;
    dp[0][1] = A[1];
    dp[0][2] = A[2];
    dp[1][2] = dp[0][1] + A[2];
    /*DP*/
    for(int i=3;i<=N;i++){
        //Case 1
        dp[i-2][i] = dp[i-3][i-2];
        if(i-4 >= 0) dp[i-2][i] = max(dp[i-2][i], dp[i-4][i-2]);
        dp[i-2][i] += A[i];
        
        //Case 2
        dp[i-1][i] = dp[i-3][i-1] + A[i];
    }

    cout<<max(dp[N-1][N], dp[N-2][N]);
    return 0;
}