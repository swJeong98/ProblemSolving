/* BOJ 16920 확장 게임 - 2022.08.24 */
#include <bits/stdc++.h>
using namespace std;

int N, M, P;
int jmp[10], board[1005][1005], ans[10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<tuple<int,int,int>> Q[10];

bool finish(){
    for(int i=1;i<=P;i++){
        if(!Q[i].empty()) return false;
    }
    return true;
}

void traverse(int player){
    queue<tuple<int,int,int>> tmp;
    while(!Q[player].empty()){
        int curX, curY, dist;
        tie(curX, curY, dist) = Q[player].front(); Q[player].pop();
        if(dist == jmp[player]){
            tmp.push({curX, curY, 0});
            continue;
        }

        for(int dir=0;dir<4;dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(board[nx][ny] != 0) continue;
            board[nx][ny] = player;
            Q[player].push({nx, ny, dist+1});
        }
    }
    Q[player] = tmp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>P;
    for(int i=1;i<=P;i++) cin>>jmp[i];

    for(int i=1;i<=N;i++){
        string s; cin>>s;
        for(int j=1;j<=M;j++){
            if(isdigit(s[j-1])) {
                board[i][j] = s[j-1] - '0';
                Q[board[i][j]].push({i, j, 0});
            }
            else if(s[j-1] == '.') board[i][j] = 0;
            else board[i][j] = -1;
        }
    }

    while(!finish()){
        for(int i=1;i<=P;i++) traverse(i);
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j] <= 0) continue;
            ans[board[i][j]] += 1;
        }
    }
    
    for(int i=1;i<=P;i++) cout<<ans[i]<<' ';

    return 0;
}
