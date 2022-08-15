/*BOJ 1261 알고스팟 - 2022.03.20*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char board[105][105];
bool Visit[105][105];
int broken[105][105];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N,M; cin>>M>>N;
    for(int i=1;i<=N;i++){
        string s; cin>>s;
        for(int j=1;j<=M;j++){
            board[i][j] = s[j-1];
        }
    }
    
    deque<pair<int,int>> dq;
    Visit[1][1] = true; dq.push_front({1,1});
    while(!dq.empty()){
        auto cur = dq.front(); dq.pop_front();
        for(int dir =0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
            if(Visit[nx][ny]) continue;
            Visit[nx][ny] = true;
            if(board[nx][ny] == '0'){
                dq.push_front({nx,ny});
                broken[nx][ny] = broken[cur.X][cur.Y];
            }
            else{ //board[nx][ny] == '1
                dq.push_back({nx,ny});
                broken[nx][ny] = broken[cur.X][cur.Y] + 1;
            }
        }
    }
    cout<<broken[N][M];
    return 0;
}