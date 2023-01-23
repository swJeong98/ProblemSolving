/**
 * BOJ 11404 플로이드 - 2023.01.18
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, M;
int dp[105][105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;

    for(int i=0;i<N+2;i++) fill(dp[i], dp[i]+N+2, INF);
    for(int i=1;i<=N;i++) dp[i][i] = 0;

    for(int i=0;i<M;i++) {
        int a, b, w; cin>>a>>b>>w;
        dp[a][b] = min(dp[a][b], w);
    }

    //Floyd-warshall
    for(int idx=1; idx<=N; idx++) {
        for(int row=1; row<=N; row++) {
            for(int col=1; col<=N; col++) {
                dp[row][col] = min(dp[row][col], dp[row][idx] + dp[idx][col]);
            }
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++){
            if(dp[i][j] == INF) cout<<0<<' ';
            else cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}