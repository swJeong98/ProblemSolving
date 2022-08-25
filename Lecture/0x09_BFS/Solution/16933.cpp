/* BOJ 16933 벽 부수고 이동하기 3 - 2022.08.25 */
#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dist[2][11][1005][1005];
int dx[] = {1,0,-1,0, 0};
int dy[] = {0,1,0,-1, 0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        string s; cin>>s;
        for(int j=1;j<=M;j++){
            board[i][j] = s[j-1] - '0';
        }
    }
    memset(dist, -1, sizeof(dist));
    if(N == 1 && M == 1){
        cout<<1;
        return 0;
    }

    dist[0][0][1][1] = 0;
    queue<tuple<int,int,int,int>> q;
    q.push({0,0,1,1});

    while(!q.empty()){
        int t, broken, curX, curY;
        tie(t, broken, curX, curY) = q.front(); q.pop();
        int val = dist[t][broken][curX][curY];

        for(int dir=0; dir<5; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            int nxt = (t == 0) ? 1 : 0;

            if(dir == 4){
                if(dist[nxt][broken][nx][ny] >= 0) continue;
                dist[nxt][broken][nx][ny] = val + 1;
                q.push({nxt, broken, nx, ny});
                if(nx == N && ny == M){
                    cout<<val + 2;
                    return 0;
                }
                continue;
            }

            if(t == 0){ //현재 낮인 경우
                if(board[nx][ny] == 1){
                    if(broken == K) continue;
                    if(dist[nxt][broken+1][nx][ny] >= 0) continue;
                    dist[nxt][broken+1][nx][ny] = val + 1;
                    q.push({nxt, broken+1, nx, ny});
                    if(nx == N && ny == M) {
                        cout<<val + 2;
                        return 0;
                    }
                }
                else{
                    if(dist[nxt][broken][nx][ny] >= 0) continue;
                    dist[nxt][broken][nx][ny] = val + 1;
                    q.push({nxt, broken, nx, ny});
                    if(nx == N && ny == M) {
                        cout<<val + 2;
                        return 0;
                    }
                }
            }
            else{ //현재 밤인 경우
                if(board[nx][ny] == 1) continue;
                if(dist[nxt][broken][nx][ny] >= 0) continue;
                dist[nxt][broken][nx][ny] = val + 1;
                q.push({nxt, broken, nx, ny});
                if(nx == N && ny == M) {
                    cout<<val + 2;
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}
