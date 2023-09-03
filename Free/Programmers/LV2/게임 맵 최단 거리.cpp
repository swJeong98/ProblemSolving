#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int d[105][105];
bool vis[105][105];


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int N = maps.size();
    int M = maps[0].size();
    
    queue<pair<int,int>> q;
    q.push({0, 0});
    
    vis[0][0] = true;
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if(vis[nx][ny] || maps[nx][ny] == 0) continue;
            
            vis[nx][ny] = true;
            d[nx][ny] = d[cur.X][cur.Y] + 1;
            q.push({nx, ny});
            
            if(nx == N-1 && ny == M-1) {
                return d[nx][ny] + 1;
            }
        }
    }
    return -1;
}
