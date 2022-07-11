/*BOJ 2448 별 찍기 - 11 - 2022.03.27*/
#include <bits/stdc++.h>
using namespace std;

int N;
char board[3100][6200];
int dx[] = {0,1,1,1,2,2,2,2,2};
int dy[] = {0,-1,0,1,-2,-1,0,1,2};

void MakeStar(int S, int topX, int topY){
    if(S==3){
        for(int dir=0; dir<9; dir++){
            int nx = topX + dx[dir];
            int ny = topY + dy[dir];
            if(dir!=2) board[nx][ny] = '*';
        }
        return;
    }
    MakeStar(S/2,topX,topY);
    MakeStar(S/2, topX + (S/2),topY - (S/2) );
    MakeStar(S/2, topX + (S/2),topY + (S/2)) ;
}

void printStar(int S){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=2*N; j++){
            if(board[i][j] == '*') cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>N;
    MakeStar(N,1,N);
    printStar(N);
    return 0;
}