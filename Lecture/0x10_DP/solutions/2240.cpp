/* BOJ 2240 자두나무 - 2022.05.02 */
#include <bits/stdc++.h>
using namespace std;

int dp[1005][35][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T,W; cin>>T>>W;
    int x; cin>>x;
    if(x==1) dp[1][0][1] = 1; 
    else dp[1][1][2] = 1;

    for(int i=2;i<=T;i++){
        int cur; cin>>cur;
        for(int j=0;j<=W;j++){
            dp[i][j][1] = dp[i-1][j][1];
            if(j>0 && dp[i][j][1] < dp[i-1][j-1][2])
                dp[i][j][1] = dp[i-1][j-1][2];
            if(cur == 1) dp[i][j][1] += 1;

            dp[i][j][2] = dp[i-1][j][2];
            if(j>0 && dp[i][j][2] < dp[i-1][j-1][1])
                dp[i][j][2] = dp[i-1][j-1][1];
            if(cur==2) dp[i][j][2] += 1; 
        }
    }
    int m1 = 0;
    for(int i=0;i<=W;i++){
        m1 = max(m1, dp[T][i][1]);
    }
    int m2 = 0;
    for(int i=0;i<=W;i++){
        m2 = max(m2,dp[T][i][2]);
    }
    cout<<max(m1,m2);
}