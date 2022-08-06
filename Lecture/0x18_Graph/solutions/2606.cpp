/*2606 - 바이러스*/
#include <iostream>
#include <queue>
using namespace std;

int Connected[101][101];
bool visited[101];
int N;

void BFS();

int main()
{
	scanf("%d", &N);
	int M;
	scanf("%d", &M);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		Connected[a][b] = 1;
		Connected[b][a] = 1;
	}

	BFS();
}

void BFS() {
	int count = 0;
	queue<int> q;
	q.push(1);
	visited[1] = true; 

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && Connected[a][i] != 0) {
				q.push(i);  
				visited[i] = true; count++;
			}
		}
	}
	printf("%d", count);
}