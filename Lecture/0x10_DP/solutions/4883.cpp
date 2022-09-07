/* BOJ 4883 삼각 그래프 - 2022.09.07 */
#include <bits/stdc++.h>
using namespace std;

int A[100005][4], dp[100005][4];
int dx[] = {-1,-1,-1,0};
int dy[] = {-1,0,1,-1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int TC = 0;
    while(true){
        TC += 1;
        int N; cin >> N;
        if(N == 0) break;
        for(int i=1; i <= N; i++){
            for(int j=1;j<=3;j++){
                cin>>A[i][j];
            }
        }

        for(int i=1;i<=N;i++) fill(dp[i], dp[i]+4, 1e9);
        dp[1][1] = -1, dp[1][2] = A[1][2], dp[1][3] = dp[1][2] + A[1][3];
        for(int i=2;i<=N;i++){
            for(int j=1;j<=3;j++){
                for(int dir=0;dir<4;dir++){
                    int preX = i + dx[dir];
                    int preY = j + dy[dir];
                    if(preX < 1 || preX > N || preY < 1 || preY > 3) continue;
                    if(preX == 1 && preY == 1) continue;
                    dp[i][j] = min(dp[i][j], dp[preX][preY] + A[i][j]);
                }
            }
        }

        cout<<TC<<". "<<dp[N][2]<<'\n';
    }

    return 0;
}