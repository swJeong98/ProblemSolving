/* BOJ 1967 트리의 지름 - 2022.08.06 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> adj[10005];
int par[10005];

int dfs(int cur){
    int mx = 0;
    int val = 0;
    for(auto nxt : adj[cur]){
        if(par[cur] == nxt.X) {
            val = nxt.Y;
            continue;
        }
        mx = max(mx, dfs(nxt.X));
    }
    return mx + val;
}

int start(int src){
    vector<int> ans;
    for(auto nxt : adj[src]){
        if(nxt.X == par[src]) continue;
        ans.push_back(dfs(nxt.X));
    }
    if(!ans.empty()) sort(ans.begin(), ans.end(), greater<>());

    if(ans.size() < 1) return 0;
    else if(ans.size() == 1) return ans[0];
    else return ans[0] + ans[1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N-1;i++){
        int a, b, w; cin>>a>>b>>w;
        par[b] = a;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int mx = 0;
    for(int i=1;i<=N;i++) mx = max(mx, start(i));
    cout<<mx;
    return 0;
}