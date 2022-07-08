/* BOJ 11967 불 켜기 - 2022.07.02 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> board[105][105]; 
bool vis[105][105];   //방문했는가?
bool light[105][105]; //불이 켜져있는가?
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N,M; cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        board[a][b].push_back({c,d});
    }

    queue<pair<int,int>> q;
    vis[1][1] = true;
    light[1][1] = true;
    q.push({1,1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : board[cur.X][cur.Y]){
            if(vis[nxt.X][nxt.Y]) continue;
            bool isAdvance = false;
            for(int dir=0;dir<4;dir++){
                int nx = nxt.X + dx[dir];
                int ny = nxt.Y + dy[dir];
                if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if(vis[nx][ny]) isAdvance = true;
            }
            if(isAdvance){
                vis[nxt.X][nxt.Y] = true;
                q.push({nxt.X,nxt.Y});
            }
            light[nxt.X][nxt.Y] = true;
        }

        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if(vis[nx][ny] || !light[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(light[i][j]) ans += 1;
        }
    }
    cout<<ans;
    return 0;
}