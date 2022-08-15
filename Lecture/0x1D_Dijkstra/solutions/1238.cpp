/* BOJ 1238 파티 - 2022.05.23 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> adj[1005];
int dist[1005][1005];
int N, M, K;
const int INF = 1e9 + 5;

void dijkstra(int src){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dist[src][src] = 0;
	pq.push({dist[src][src], src});

	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(dist[src][cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(dist[src][nxt.Y] <= dist[src][cur.Y]+nxt.X) continue;
			dist[src][nxt.Y] = dist[src][cur.Y]+nxt.X;
			pq.push({dist[src][nxt.Y],nxt.Y});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a,b,w; cin>>a>>b>>w;
		adj[a].push_back({w,b});
	}
	for(int i=0;i<=N+1;i++) fill(dist[i],dist[i]+N+1, INF);
	for(int i=1;i<=N;i++) dijkstra(i);

	int ans = -1;
	for(int i=1;i<=N;i++){
		ans = max(ans, dist[i][K] + dist[K][i]);
	}
	cout<<ans;
	return 0;
}