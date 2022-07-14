/*BOJ 14502번 연구소 (백트래킹 이용한 풀이) - 2022.01.25*/
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int board1[9][9];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> blank; //빈칸의 좌표 위치를 저장할 벡터
vector<pair<int,int>> wall;
int N,M;
int ans;

void func(int k,int st);
int BFS();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board1[i][j];
            if(board1[i][j] == 0) blank.push_back({i,j});
        }
    }
    func(0,0);
    cout<<ans;
}

void func(int k,int st){
    if(k==3){
        int res = BFS(); //안전 영역의 개수 반환
        ans = max(ans,res);
        return;
    }
    for(int i=st;i<blank.size();i++){
        board1[blank[i].X][blank[i].Y] = 1;
        func(k+1,i+1);
        board1[blank[i].X][blank[i].Y] = 0;
    }
}

int BFS(){
    queue<pair<int,int>> Q;
    bool visit[9][9] = {};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board1[i][j]==2) Q.push({i,j});
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
            if(board1[nx][ny] != 0) continue;
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
    
    int ret = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visit[i][j] && board1[i][j]==0) ret++;
        }
    }
    return ret;
}