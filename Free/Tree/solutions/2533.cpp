/* BOJ 2533 사회망 서비스(SNS)  - 2022.07.17 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000005];
int dp[1000005][2];
bool vis[1000005];
int N;

void traverse(int nd){
    vis[nd] = true;
    dp[nd][0] = 1;
    for(auto nxt : adj[nd]){
        if(vis[nxt]) continue;
        traverse(nxt);
        dp[nd][1] += dp[nxt][0];
        dp[nd][0] += min(dp[nxt][1], dp[nxt][0]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //임의 노드 출발 - 1로 설정.
    traverse(1);
    int ans = min(dp[1][0], dp[1][1]);
    cout<<ans;
    return 0;
}