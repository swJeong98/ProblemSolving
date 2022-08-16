/* BOJ 1707 이분 그래프 - 2022.08.16 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<int> adj[20005];
bool vis[20005], isValid = true;
int state[20005];
int V, E;

void bfs(int src){
    state[src] = 1;
    vis[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt]){
                if(state[cur] == state[nxt]) {isValid = false; return;}
                continue;
            }
            vis[nxt] = true;
            q.push(nxt);
            state[nxt] = (state[cur] == 0) ? 1 : 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int K; cin>>K;
    while(K--){
        cin>>V>>E;
        isValid = true;
        for(int i=1;i<=V;i++) adj[i].clear();
        fill(vis+1, vis+V+1, false);
        fill(state+1, state+V+1, -1);

        for(int i=0;i<E;i++) {
            int a, b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1;i<=V;i++){
            if(vis[i]) continue;
            bfs(i);
        }
        string s = isValid ? "YES\n" : "NO\n";
        cout<<s;
    }
    return 0;
}
