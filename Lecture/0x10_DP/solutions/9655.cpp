/* BOJ 9655 돌 게임 - 2022.09.06 */
#include <bits/stdc++.h>
using namespace std;

string dp[1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    dp[1] = "SK", dp[2] = "CY", dp[3] = "SK";
    for(int i=4;i<=N;i++) dp[i] = (dp[i-1] == "SK") ? "CY" : "SK";

    cout<<dp[N];
    return 0;
}