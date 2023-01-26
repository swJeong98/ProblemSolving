/* BOJ 15900 나무 탈출 - 2022.10.26 */
#include <bits/stdc++.h>
using namespace std;

int N, total;
vector<int> adj[500005];
bool vis[500005];

void dfs(int cur, int cnt){
    bool isLeaf = true;
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        isLeaf = false;
        vis[nxt] = true;
        dfs(nxt, cnt + 1);
    }
    if(isLeaf) total += cnt;
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N-1;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis[1] = true;
    dfs(1, 0);

    cout<< ( (total % 2 == 1) ? "Yes" : "No" );
    return 0;
}