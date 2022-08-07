/* BOJ 1325 효율적인 해킹 - 2022.08.07 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[10005];
int ans[10005], vis[10005];

int dfs(int cur){
    int res = 1;
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        res += dfs(nxt);
    }
    return res;
}

int start(int src){
    fill(vis+1, vis+N+1, false);
    vis[src] = true;
    return dfs(src);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b; 
        adj[b].push_back(a);
    }

    for(int i=1;i<=N;i++) ans[i] = start(i);

    int mx = -1;
    vector<int> v;

    for(int i=1;i<=N;i++){
        if(mx < ans[i]){
            mx = ans[i];
            v.clear();
            v.push_back(i);
        }
        else if(mx == ans[i]) v.push_back(i);
    }

    for(auto elem : v) cout<<elem<<" ";
    return 0;
}