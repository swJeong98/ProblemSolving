/* BOJ 16929 Two Dots - 2023.10.06*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
char board[55][55];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool flag;
bool vis[55][55];

void dfs(pair<int,int> src, int x, int y, int cnt) {

    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(board[nx][ny] != board[src.X][src.Y]) continue;
        if(cnt >= 4 && vis[nx][ny]) {
            if(src.X == nx && src.Y == ny) {
                flag = true;
                return;
            }
        }
        if(vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(src, nx, ny, cnt+1);
    }
}

void clear() {
    for(int i=0; i<N+2; i++) fill(vis[i], vis[i]+M+2, false);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        string s; cin>>s;
        for(int j=1; j<=M; j++) {
            board[i][j] = s[j-1];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            clear();
            
            vis[i][j] = true;
            dfs({i, j}, i, j, 1);
            if(flag) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;   
}