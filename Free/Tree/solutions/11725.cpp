#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int par[100005];

void dfs(int cur){
    for(int nxt : adj[cur]){
        if(nxt == par[cur]) continue;
        par[nxt] = cur;
        dfs(nxt);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=1;i<N;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=N;i++) cout<<par[i]<<'\n';
    return 0;
}