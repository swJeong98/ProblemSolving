/*BOJ 7576번 토마토 - 2022.01.05*/

#include <iostream>
#include <queue>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

int container[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	//가장 초기 상태에서의 익은 토마토 위치 queue에 저장
	queue<PI> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> container[i][j];
			if (container[i][j] == 1)
				q.push({ i,j });
			if (container[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	//Do BFS
	while (!q.empty()) {
		PI cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}