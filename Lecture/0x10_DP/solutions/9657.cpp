/* BOJ 9657 돌 게임 3 - 2022.09.07 */
#include <bits/stdc++.h>
using namespace std;

string dp[1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    dp[1] = "SK", dp[2] = "CY", dp[3] = "SK", dp[4] = "SK", dp[5] = "SK";
    int N; cin>>N;
    for(int i=6; i<=N; i++){
        string val1 = dp[i-1];
        string val2 = dp[i-3];
        string val3 = dp[i-4];
        if(val1 == "CY" || val2 == "CY" || val3 == "CY") dp[i] = "SK";
        else dp[i] = "CY";
    }
    cout<<dp[N];
    return 0;
}