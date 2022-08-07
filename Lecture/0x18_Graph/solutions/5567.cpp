/* BOJ 5567 결혼식  - 2022.08.07 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int dist[505];
int N, M; 

void bfs(){
    queue<int> q;
    q.push(1);
    fill(dist, dist+N+1, -1);
    dist[1] = 0;

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
    bfs();
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == 1 || dist[i] == 2) ans += 1;
    }
    cout<<ans;
    return 0;
}