/* BOJ 1389 케빈 베이컨의 6단계 법칙 - 2022.08.07 */
#include <bits/stdc++.h>
using namespace std;

int N, M; 
bool adj[105][105];
int dist[105], ans[105];

void bfs(int src){
    fill(dist+1, dist+N+1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=1;i<=N;i++){
            if(!adj[cur][i]) continue;
            if(dist[i] != -1) continue;
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }

    int res = 0;
    for(int i=1;i<=N;i++){
        if(i == src) continue;
        res += dist[i];
    }
    ans[src] = res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    for(int i=1;i<=N;i++) bfs(i);

    int mn = 1e6;
    int mnNode;

    for(int i=1;i<=N;i++){
        if(mn > ans[i]) {
            mn = ans[i];
            mnNode = i;
        }
    }
    cout<<mnNode;
    return 0;
}