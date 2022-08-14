/* BOJ 15681 트리와 쿼리 - 2022.08.14 */
#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
int sz[100005], vis[100005];
vector<int> adj[100005];

int dfs(int cur){
    int res = 1;
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        res += dfs(nxt);
    }
    return sz[cur] = res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>R>>Q;
    for(int i=0;i<N-1;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis[R] = true;
    dfs(R);
    while(Q--){
        int x; cin>>x;
        cout<<sz[x]<<'\n';
    }
    return 0;
}
