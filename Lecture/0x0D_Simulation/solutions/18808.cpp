/* BOJ 18808 스티커 붙이기 - 2022.08.13 */
#include <bits/stdc++.h>
using namespace std;

int N, M, K, r, c;
int board[45][45];
int sticker[15][15];

void Input(){
    cin>>r>>c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>sticker[i][j];
}

bool check(int x, int y){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(sticker[i][j] == 1) board[x+i][y+j] = 1;
        }
    }
    return true;
}

void rotate(){
    int tmp[15][15];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            tmp[i][j] = sticker[i][j];

    for(int i=0;i<c;i++)
        for(int j=0;j<r;j++)
            sticker[i][j] = tmp[r-1-j][i];
    swap(r, c);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        Input();
        bool ok = false;
        for(int dir=0; dir<4; dir++){
            for(int j=0;j<=N-r;j++){
                if(ok) break;
                for(int k=0;k<=M-c;k++){
                    if(check(j, k)){
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) break;
            rotate();
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans += board[i][j];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
