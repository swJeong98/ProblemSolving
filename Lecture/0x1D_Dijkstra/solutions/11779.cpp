#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 100000000
using namespace std;

int Distance[1001];
int path[1001];
vector<pair<int, int>> Vertex[1001];
vector<int> vec;
int n, m;

void dijkstra(int);
//void getPath(int);

int main()
{
	scanf("%d %d", &n, &m);
	int a, b, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		Vertex[a].push_back(make_pair(b, w));
	}

	for (int i = 1; i <= n; i++) {
		Distance[i] = INF;
	}

	int source, destination;
	scanf("%d %d", &source, &destination);

	dijkstra(source);
	printf("%d\n", Distance[destination]);

	int temp = destination;
	while (temp) {
		vec.push_back(temp);
		temp = path[temp];
	}
	int size = vec.size();
	printf("%d\n", size);
	for (int i = size - 1; i >= 0; i--) {
		printf("%d ", vec[i]);
	}
}

void dijkstra(int source) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, source));
	Distance[source] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (Distance[cur] < cost) continue;

		for (int i = 0; i < Vertex[cur].size(); i++) {
			int next = Vertex[cur][i].first;
			int nCost = Vertex[cur][i].second;

			if (Distance[next] > cost + nCost) {
				Distance[next] = cost + nCost;
				pq.push(make_pair(-Distance[next], next));
				path[next] = cur;
			}
		}
	}
}