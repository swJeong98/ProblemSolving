/*BOJ 2294번 동전 2 - 2022.02.11*/
#include <iostream>
#include <algorithm>
using namespace std;

int C[100];
int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>C[i];
    sort(C,C+N,greater<int>());
    
    for(int i=0;i<N;i++){
        for(int j=1;j<=K;j++){
            if(C[i]<j){
                if(dp[j-C[i]] == 0) {}//do nothing
                else{
                    if(dp[j]==0) dp[j] = dp[j-C[i]] + 1;
                    else dp[j] = min(dp[j],dp[j-C[i]]+1);
                }
            }
            else if(C[i]==j){
                dp[j] = 1;
            }
            else{ //C[i]>j
                //do nothing
            }
        }
        //for(int i=0;i<=K;i++) cout<<dp[i]<<' ';
        //cout<<'\n';
    }
    if(dp[K]==0) cout<<-1;
    else cout<<dp[K];
}