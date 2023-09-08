#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

bool vis[105][105];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int N = maps.size(), M = maps[0].size();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maps[i][j] == 'X') continue;
            if(vis[i][j]) continue;
            int sum = 0;
            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = true;
            sum += (maps[i][j] - '0');
            while(!q.empty()) {
                auto cur = q.front(); q.pop();
                
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
                    if(maps[nx][ny] == 'X' || vis[nx][ny]) continue;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    
                    sum += (maps[nx][ny] - '0');
                    
                }
            }
            if(sum != 0) answer.push_back(sum);
        }
    }
    //섬에서 머무를 수 있는 기간을 오름차순으로 담아 리턴 
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
