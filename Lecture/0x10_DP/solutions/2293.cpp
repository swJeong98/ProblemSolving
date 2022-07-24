/*BOJ 2293번 동전 - 2022.02.11*/
#include <iostream>
#include <algorithm>
using namespace std;

int C[100];
int dp[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>C[i];
    sort(C,C+N);
    
    dp[0] = 1;
    for(int i=0;i<N;i++){
        for(int j=1;j<=K;j++){
            if(j >= C[i]) dp[j] += dp[j-C[i]];
        }
    }
    cout<<dp[K];
}