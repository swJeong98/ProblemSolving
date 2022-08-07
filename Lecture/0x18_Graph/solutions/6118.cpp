/* BOJ 6118 숨바꼭질 - 2022.08.08 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[20005];
int dist[20005];

void bfs(int src){
    fill(dist+1, dist+N+1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
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

    bfs(1);
    vector<int> ans;
    int mx = -1;
    for(int i=1;i<=N;i++){
        if(mx < dist[i]){
            mx = dist[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(mx == dist[i]) ans.push_back(i);
    }

    cout<<ans[0]<<" "<<dist[ans[0]]<<" "<<ans.size();
    return 0;
}
