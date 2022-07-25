/* BOJ 7570 줄 세우기 - 2022.07.02 */
#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    int mx = 0;
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        dp[x] = dp[x-1] + 1;
        mx = max(mx, dp[x]);
    }
    cout<<N-mx;
}