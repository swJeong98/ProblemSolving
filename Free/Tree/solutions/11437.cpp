/* BOJ 11437 LCA - 2022.07.21 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> adj[50005];
int depth[50005], par[50005];
bool vis[50005];
int N;

void dfs(int cur, int d, int parent){
    vis[cur] = true;
    par[cur] = parent;
    depth[cur] = d;

    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt, d+1, cur);
    }
}

int LCA(int a, int b){
    bool check[50005] = {};
    int cur = a;
    while(1){
        if(cur == 0) break;
        check[cur] = true;
        cur = par[cur];
    }

    int mxDepth = -1;
    int ans = -1;

    cur = b;
    while(1){
        if(cur == 0) break;
        if(!check[cur]) {
            cur = par[cur];
            continue;
        }
        if(mxDepth < depth[cur]){
            ans = cur;
            mxDepth = depth[cur];
        }
        cur = par[cur];
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N-1;i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 0);
    int M; cin>>M;
    while(M--){
        int a, b; cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}