/* BOJ 1520 내리막 길 - 2022.07.19 */
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N, M;
int board[505][505];
int dp[505][505];

int dfs(int x,int y){
    if(dp[x][y] != -1) return dp[x][y];
    if(x == N && y == M) return 1;
    dp[x][y] = 0; //visit
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(board[x][y] <= board[nx][ny]) continue;
        dp[x][y] += dfs(nx,ny);
    }
    return dp[x][y];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<N+1;i++) fill(dp[i], dp[i]+M+1, -1);
    cout<< dfs(1,1);
    return 0;
}