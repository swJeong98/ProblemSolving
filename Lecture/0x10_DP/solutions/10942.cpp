/* BOJ 10942 팰린드롬? - 2022.06.27 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int A[2005];
int dp[2005][2005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            //Out of Bounds
            if(j+i-1 > N) continue;
            if(i==1){
                dp[j][j+i-1] = 1;
                continue;
            }
            if(i==2){
                if(A[j] == A[j+i-1]) dp[j][j+i-1] = 1;
                else dp[j][j+i-1] = 0;
                continue;
            }
            if(A[j] != A[j+i-1]){
                dp[j][j+i-1] = 0;
                continue;
            }
            else{
                dp[j][j+i-1] = dp[j+1][j+i-2];
                continue;
            }
        }
    }

    //Query 
    int M; cin>>M;
    for(int i=0;i<M;i++){
        int S,E; cin>>S>>E;
        if(S == E) cout<<1<<endl;
        else if(A[S] != A[E]) cout<<0<<endl;
        else{
            cout<<dp[S][E]<<'\n';
        }
    }
    return 0;
}