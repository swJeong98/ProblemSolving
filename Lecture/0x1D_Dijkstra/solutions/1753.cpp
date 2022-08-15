#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200000
using namespace std;

vector<pair<int, int>> edge[20001];
vector<int> Distance(20001, INF);

void dijkstra(int source);

int main()
{
	int V, E; 
	scanf("%d %d", &V, &E);
	int source;
	scanf("%d", &source);

	int a, b, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &w);
		edge[a].push_back(make_pair(b, w));
	}

	dijkstra(source);
	for (int i = 1; i <= V; i++) {
		if (Distance[i] == INF) {
			printf("INF\n");
		}
		else printf("%d\n", Distance[i]);
	}

}

void dijkstra(int source) {
	Distance[source] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, source));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[current].size(); i++) {
			int next = edge[current][i].first;
			int nCost = edge[current][i].second;
			if (Distance[next] > cost + nCost) {
				Distance[next] = cost + nCost;
				pq.push(make_pair(-Distance[next], next));
			}
		}
	}
}