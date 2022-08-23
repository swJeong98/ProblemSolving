/* BOJ 14499 주사위 굴리기 - 2022.08.23 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

struct Dice{
    int state[7] = {0, 1, 2, 3, 4, 5, 6};
    int arr[7] = {0, 0, 0, 0, 0, 0, 0};
};

int trans[5][7] = {
        {},
        {0, 4, 3, 1, 2, 5, 6},
        {0, 3, 4, 2, 1, 5, 6},
        {0, 5, 6, 3, 4, 2, 1},
        {0, 6, 5, 3, 4, 1, 2}
};

int N, M;
int board[25][25];
Dice d;

bool OutOfBounds(int x, int y, int dir){
    if(dir == 1) return x < 1 || x > N || y+1 < 1 || y+1 > M;
    else if(dir == 2) return x < 1 || x > N || y-1 < 1 || y-1 > M;
    else if(dir == 3) return x-1 < 1 || x-1 > N || y < 1 || y > M;
    else return x+1 < 1 || x+1 > N || y < 1 || y > M;
}

void rotate(int dir){
    Dice tmp;
    for(int i=1;i<=6;i++) tmp.state[i] = trans[dir][i];
    for(int i=1;i<=6;i++) tmp.arr[i] = d.arr[trans[dir][i]];
    d = tmp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;

    pair<int,int> pos;
    cin>>pos.X>>pos.Y;
    pos.X += 1, pos.Y += 1;

    int Q; cin>>Q;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }

    while(Q--){
        int dir; cin>>dir;
        if(OutOfBounds(pos.X, pos.Y, dir)) continue;

        if(dir == 1) pos.Y += 1;
        else if(dir == 2) pos.Y -= 1;
        else if(dir == 3) pos.X -= 1;
        else pos.X += 1;

        rotate(dir);

        if(board[pos.X][pos.Y] == 0) board[pos.X][pos.Y] = d.arr[2];
        else {
            d.arr[2] = board[pos.X][pos.Y];
            board[pos.X][pos.Y] = 0;
        }
        cout<<d.arr[1]<<'\n';
    }
    return 0;
}
