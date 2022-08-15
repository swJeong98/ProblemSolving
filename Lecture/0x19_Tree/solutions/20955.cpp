/* BOJ 20955 민서의 응급 수술 - 2022.08.15 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[100005];
int sz[100005];
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

int CountEdge(int cur){
    int ret = 0;
    vis[cur] = true;
    queue<int> q;
    q.push(cur);
    while(!q.empty()){
        auto now = q.front(); q.pop();
        ret += adj[now].size();
        for(auto nxt : adj[now]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    return ret/2;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> start;
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        vis[i] = true;
        start.push_back(i);
        dfs(i);
    }
    fill(vis+1, vis+N+1, false);

    vector<int> res;
    for(auto elem : start) res.push_back(CountEdge(elem));

    int ans = 0;
    for(int i=0;i<start.size(); i++){
        int want = sz[start[i]] - 1;
        ans += (res[i] - want);
    }
    ans += ( (int)start.size() - 1 );
    cout<<ans;

    return 0;
}
