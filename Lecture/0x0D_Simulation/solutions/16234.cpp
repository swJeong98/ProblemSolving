/* BOJ 16234 인구 이동 - 2022.04.09 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N,L,R;

bool OOB(int x,int y){
    return x<1 || x>N || y<1 || y>N;
}

bool isImigrate(){
    bool rval = false;
    bool Visit[55][55] = {};
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(Visit[i][j]) continue;
            Visit[i][j] = true;
            q.push({i,j});
            queue<pair<int,int>> res;
            res.push({i,j});
            int sum = 0;
            sum += board[i][j];
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(OOB(nx,ny)) continue;
                    if(Visit[nx][ny]) continue;
                    int target = abs(board[cur.X][cur.Y]-board[nx][ny]);
                    if(target >= L && target <=R){
                        q.push({nx,ny});
                        res.push({nx,ny});
                        sum += board[nx][ny];
                        Visit[nx][ny] = true;
                    }
                }
            }
            if(res.size() > 1) rval = true;
            int val = sum / res.size();
            while(!res.empty()){
                board[res.front().X][res.front().Y] = val;
                res.pop();
            }
        }
    }
    return rval;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>N>>L>>R;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>board[i][j];

    int ans = 0;
    while(isImigrate()) ans++;
    cout<<ans;
    return 0;
}