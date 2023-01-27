/* BOJ 1240 노드사이의 거리 - 2022.05.14 */
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1005];
int ans[1005][1005];

void calculateDist(int st, int src, int parent, int dist){
    ans[st][src] = dist;

    int child = 0;
    for(auto i=0; i<adj[src].size(); i++){
        int nd = adj[src][i].first;
        if(nd != parent) child++;
    }

    if(child == 0) return;

    for(auto i=0;i<adj[src].size();i++){
        int nd = adj[src][i].first, w = adj[src][i].second;
        if(nd != parent) {
            calculateDist(st, nd, src, dist+w);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M; cin>>N>>M;
    for(int i=1;i<N;i++){
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    for(int i=1;i<=N;i++){
        calculateDist(i, i, -1, 0);
    }

    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        cout<<ans[a][b]<<'\n';
    }
}