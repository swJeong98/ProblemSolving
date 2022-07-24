/*BOJ 9084번 동전 - 2022.02.11*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        int C[21] = {};
        for(int i=1;i<=N;i++) cin>>C[i];
        int M; cin>>M;
        int dp[21][10001] = {};
        
        for(int i=0;i<=N;i++) dp[i][0] = 1;

        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                dp[i][j] = dp[i-1][j];
                if(C[i]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i][j-C[i]];
                }
            }
        }
        cout<<dp[N][M]<<'\n';
    }
}