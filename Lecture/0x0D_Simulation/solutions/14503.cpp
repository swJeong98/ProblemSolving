/* BOJ 14503 로봇 청소기 - 2022.05.05 */
#include <bits/stdc++.h>
using namespace std;

int N,M; 
int board[55][55];
bool Visit[55][55];

//(x,y)기준 dir방향의 왼쪽 칸이 아직 청소하지 않은 빈 공간인지 확인하는 함수
bool left(int x,int y,int dir){
    int nx = -1, ny = -1;
    if(dir==0) {nx = x, ny = y-1;}
    if(dir==1) {nx = x-1, ny = y;}
    if(dir==2) {nx = x, ny = y+1;}
    if(dir==3) {nx = x+1, ny = y;}
    return !Visit[nx][ny] && board[nx][ny] == 0;
}

//(x,y)기준 dir방향의 뒤 칸이 벽인지 확인하는 함수
bool isWall(int x, int y, int dir){
    int nx = -1, ny = -1;
    if(dir==0) {nx = x+1, ny = y;}
    if(dir==1) {nx = x, ny = y-1;}
    if(dir==2) {nx = x-1, ny = y;}
    if(dir==3) {nx = x, ny = y+1;}
    return nx==1 || nx==N || ny==1 ||ny ==M ||board[nx][ny] == 1;
}

//그냥 방향만 왼쪽으로 바꾸는 함수
int turnleft(int dir){
    dir -= 1;
    if(dir<0) return 3;
    else return dir;
}

//(x,y)의 dir방향을 볼 때, 왼쪽으로 회전/이동하는 함수
int Goleft(int* xptr, int* yptr, int dir){
    int x = *xptr, y = *yptr;
    if(dir==0){
        dir = 3; 
        y -= 1;
    }
    else if(dir==1){
        dir = 0;
        x -= 1;
    }
    else if(dir==2){
        dir = 1;
        y += 1;
    }
    else if(dir==3){
        dir = 2;
        x += 1;
    }
    *xptr = x, *yptr = y;
    Visit[x][y] = true;
    return dir;
}

//뒤쪽으로 후진 이동하는 함수
void Goback(int* xptr, int* yptr,int dir){
    int x = *xptr; int y = *yptr;
    if(dir==0) x++;
    if(dir==1) y--;
    if(dir==2) x--;
    if(dir==3) y++;
    *xptr = x; *yptr = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    int x,y,dir; cin>>x>>y>>dir;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }

    pair<int,int> pos = {x+1,y+1};
    int curX = pos.first, curY = pos.second;
    int cycle = 0;
    Visit[curX][curY] = true;
    while(1){
        if(left(curX,curY,dir)){
            dir = Goleft(&curX,&curY,dir);
            cycle = 0;
        }
        else{
            dir = turnleft(dir); 
            cycle++;
        }
        if(cycle == 4){
            if(isWall(curX,curY,dir)) break;
            else {Goback(&curX,&curY,dir); cycle = 0;}
        }
    }
    
    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==1 || i==N ||j==1||j==M) continue;
            if(Visit[i][j]) ans++;
        }
    }
    cout<<ans;
}