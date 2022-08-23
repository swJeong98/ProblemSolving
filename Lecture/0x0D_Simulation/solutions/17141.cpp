/* BOJ 17141 연구소 2 - 2022.08.23 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int board[55][55];
vector<pair<int,int>> pos;
vector<pair<int,int>> virus;
int ans = 1e5;

int BFS(){
    int dist[55][55];
    for(int i=1;i<N+2;i++) fill(dist[i], dist[i]+N+2, -1);

    queue<pair<int,int>> q;
    for(auto elem : virus){
        dist[elem.X][elem.Y] = 0;
        q.push({elem.X, elem.Y});
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }

    int ret = -1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j] == 1) continue;
            if(dist[i][j] == -1) return 1e5;
            ret = max(ret, dist[i][j]);
        }
    }
    return ret;
}
void solve(int idx, int cnt){
    if(idx == (int)pos.size()){
        if(cnt < M) return;
        ans = min(ans, BFS());
        return;
    }
    if(cnt == M){
        ans = min(ans, BFS());
        return;
    }
    virus.push_back({pos[idx].X, pos[idx].Y});
    solve(idx+1, cnt+1);
    virus.pop_back();
    solve(idx+1, cnt);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            if(board[i][j] == 2) pos.push_back({i,j});
        }
    }

    solve(0, 0);
    if(ans == 1e5) cout << -1;
    else cout<<ans;

    return 0;
}