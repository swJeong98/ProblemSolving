/* BOJ 15486 퇴사 2 - 2022.09.02 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1500005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++){
        int t; ll p; cin>>t>>p;
        dp[i] = max(dp[i-1], dp[i]);
        if(i + t -1 > N) continue;
        dp[i+t] = max(dp[i+t], dp[i] + p);
    }
    cout<<*max_element(dp+1, dp+N+2);
    return 0;
}