/* BOJ 1932 정수 삼각형 -  2022.07.02 */
#include <bits/stdc++.h>
using namespace std;

int dp[505][505];

int main()
{ 
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    cin>>dp[1][1];
    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            int x; cin>>x;
            int val1 = -1, val2 = -1;
            if(j != 1) val1 = dp[i-1][j-1];
            if(j != i) val2 = dp[i-1][j];
            dp[i][j] = max(val1, val2) + x;
        }
    }
    cout<<*max_element(dp[N] + 1, dp[N]+1+N);
    return 0;
}