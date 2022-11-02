/*BOJ 1780번 종이의 개수 - 2021.01.17*/
#include <iostream>
using namespace std;

int board[2188][2188];
int cnt[3];
void func(int,int,int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    func(N,1,1);
    for(int i=0;i<3;i++) cout<<cnt[i]<<'\n';
}

void func(int N,int r,int c){
    if(N==1){ 
        cnt[board[r][c]+1]++;
        return;
    }

    bool isDifferent = false;
    int first = board[r][c];
    for(int i=r;i<r+N;i++){
        for(int j=c;j<c+N;j++){
            if(board[i][j]==first) continue;
            isDifferent = true;
            break;
        }
    }
    if(!isDifferent) {
        cnt[first+1]++;
        return;
    }
    //9개로 나누어 탐색한 결과 합침.
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int nr = r + (N/3)*i;
            int nc = c + (N/3)*j;
            func(N/3,nr,nc);
        }
    }
}