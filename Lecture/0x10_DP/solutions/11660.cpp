/*BOJ 11660번 구간 합 구하기 5 - 2022.02.21*/
#include <iostream>
using namespace std;

int board[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int tmp; cin>>tmp;
            board[i][j] = board[i][j-1] + tmp;
        }
    }
    
    while(M--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int ans = 0;
        for(int i=a;i<=c;i++){
            ans += (board[i][d]-board[i][b-1]);
        }
        cout<<ans<<'\n';
    }
}