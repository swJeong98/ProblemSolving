/*BOJ 2133번 타일 채우기 - 2022.03.06*/
#include <iostream>
using namespace std;

long long dp[35];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    dp[0] = 1; dp[1] = 0; dp[2] = 3;
    for(int i=3;i<=N;i++){
        dp[i] = 3*dp[i-2];
        if(i%2 == 0){
            for(int j=4;j<=i;j+=2) dp[i] += 2*dp[i-j];
        }
    }
    cout<<dp[N];
    return 0;
}