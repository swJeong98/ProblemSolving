/*BOJ 2447번 별 찍기 10 - 2021.01.17*/
#include <iostream>
using namespace std;

char board[2188][2188];
void MakeStar(int N,int r,int c);
void Makeblank(int N,int r,int c);
void printStar(int N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N; //N은 3의 제곱수로 주어짐.
    MakeStar(N,1,1);
    printStar(N);
}

void MakeStar(int N,int r,int c){
    if(N==3){
        for(int i=r;i<r+N;i++){
            for(int j=c;j<c+N;j++){
                if(i==r+1 && j==c+1) {
                    board[i][j] = ' ';
                    continue;
                }
                board[i][j] = '*';
            }
        }
        return;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1) Makeblank(N/3,r + (N/3)*i,c + (N/3)*j);
            else{
                MakeStar(N/3,r + (N/3)*i,c + (N/3)*j);
            }
        }
    }
}

void Makeblank(int N,int r,int c){
    for(int i=r;i<r+N;i++){
        for(int j=c;j<c+N;j++){
            board[i][j] = ' ';
        }
    }
}

void printStar(int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}