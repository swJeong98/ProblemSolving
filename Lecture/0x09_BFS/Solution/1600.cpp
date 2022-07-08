/*BOJ 1600 말이 되고픈 원숭이 - 2022.03.23*/
#include <bits/stdc++.h>
#define TP tuple<int,int,int>
#define H get<0>
#define X get<1>
#define Y get<2>
using namespace std;

int N,M,K;
int jmpX[] = {-2,-1,1,2,2,1,-1,-2};
int jmpY[] = {1,2,2,1,-1,-2,-2,-1};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int board[205][205];
int dist[35][205][205];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>K>>M>>N;
    //이 경우를 제외하면 답이 0이 될 수 없음.
    if(N==1 && M==1){ 
        cout<<0;
        return 0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0; i<=K;i++) dist[i][1][1] = 1;
    queue<TP> q; q.push({0,1,1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir=0; dir<8; dir++){
            if(H(cur) >= K) break;
            int nx = X(cur) + jmpX[dir];
            int ny = Y(cur) + jmpY[dir];
            if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
            if(board[nx][ny] == 1) continue;
            if(dist[H(cur)+1][nx][ny] > 0) continue;
            dist[H(cur)+1][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1;
            q.push({H(cur)+1,nx,ny});
            if(nx==N && ny==M){
                cout<<dist[H(cur)+1][N][M] - 1;
                return 0;
            }
        }

        for(int dir=0;dir<4;dir++){
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];
            if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
            if(board[nx][ny] == 1) continue;
            if(dist[H(cur)][nx][ny] > 0) continue;
            dist[H(cur)][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1;
            q.push({H(cur),nx,ny});
            if(nx==N && ny==M){
                cout<<dist[H(cur)][N][M] - 1;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}