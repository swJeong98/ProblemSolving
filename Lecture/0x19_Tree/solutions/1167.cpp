/* BOJ 1167 트리의 지름  - 2022.07.15 */
#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

ll N, mx, mxNode;
vector<pair<ll,ll>> adj[100005];
bool vis[100005];

void dfs(ll cur, ll dist){
    vis[cur] = true;
    if(mx < dist){
        mx = dist;
        mxNode = cur;
    }

    for(auto nxt : adj[cur]){
        if(vis[nxt.X]) continue;
        vis[nxt.X] = true;
        dfs(nxt.X, dist + nxt.Y);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        while(1){
            int a, b;
            cin>>a;
            if(a == -1) break;
            cin>>b;
            adj[x].push_back({a,b});
            adj[a].push_back({x,b});
        }
    }

    dfs(1, 0);
    fill(vis, vis+N+1, false);
    dfs(mxNode, 0);

    cout<<mx;
    return 0;
}