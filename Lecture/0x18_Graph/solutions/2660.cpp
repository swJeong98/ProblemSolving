/* BOJ 2660 회장 뽑기 - 2022.08.07 */
#include <bits/stdc++.h>
using namespace std;

int N; 
vector<int> adj[55];
int dist[55], ans[55];

void bfs(int src){
    fill(dist, dist+N+1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    ans[src] = *max_element(dist+1, dist+N+1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    while(1){
        int a, b; cin>>a>>b;
        if(a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=N;i++) bfs(i);

    int mn = 100;
    vector<int> v;

    for(int i=1;i<=N;i++){
        if(ans[i] == -1) continue;

        if(mn > ans[i]){
            mn = ans[i];
            v.clear();
            v.push_back(i);
        }
        else if(mn == ans[i]) v.push_back(i);
    }

    cout<<mn<<" "<<v.size()<<'\n';
    for(auto elem : v) cout<<elem<<" ";
    return 0;   
}