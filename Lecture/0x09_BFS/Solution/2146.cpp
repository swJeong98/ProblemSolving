/* BOJ 2146 다리 만들기 - 2022.05.07 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N; 
int board[105][105];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
//섬에 대해 Connected Component를 구하는 함수
void Markingland(int i, int j, int num){
    queue<pair<int,int>> Q;
    bool Visit[105][105] = {};
    Q.push({i,j});
    Visit[i][j] = true;
    board[i][j] = num;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<1 ||nx>N ||ny<1 ||ny>N) continue;
            if(Visit[nx][ny] || board[nx][ny] != 1) continue;
            Visit[nx][ny] = true;
            Q.push({nx,ny});
            board[nx][ny] = num;
        }
    }
}
//(i,j)가 섬의 가장자리인지 확인하는 함수
bool isEdge(int i, int j){
    int val = board[i][j];
    for(int dir=0;dir<4;dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx<1||nx>N||ny<1||ny>N) return true;
        if(board[nx][ny] != val) return true;
    }
    return false;
}
//(i,j)에서 가장 가까운 다리를 찾는 함수
int getMinDist(int i,int j){
    int val = board[i][j];
    int dist[105][105] = {};
    queue<pair<int,int>> Q;
    Q.push({i,j}); 
    dist[i][j] = 1;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<1 ||nx>N ||ny<1||ny>N) continue;
            if(board[nx][ny] == val || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
            if(board[nx][ny] != 0 && board[nx][ny] != val){//가장 빠른 다리 완성
                return dist[nx][ny] - 2;
            }
        }
    }
    return 1e5;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    
    int land = 2;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j] == 1){
                Markingland(i,j,land);
                land++;
            }
        }
    }
    
    int ans = 1e5 + 5;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j] == 0 || !isEdge(i,j)) continue;
            ans = min(ans, getMinDist(i,j));
        }
    }
    cout<<ans;
}