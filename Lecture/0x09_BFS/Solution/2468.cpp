/*BOJ 2468번 안전 영역 - 2022.01.10*/

#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int height[102][102];
bool visit[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;

void BFS(int i, int j, int h);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> height[i][j];
			mx = max(mx, height[i][j]);
		}
	}

	int ans = 1;
	for (int h = 1; h <= mx - 1; h++) {

		int area = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (height[i][j] <= h || visit[i][j]) continue;
				area++;
				BFS(i, j, h);
			}
		}
		ans = max(ans, area);
		for (int i = 0; i < N + 2; i++) fill(visit[i], visit[i] + N + 2, false);
	}
	cout << ans;
}

void BFS(int i, int j, int h) {
	visit[i][j] = true;
	queue<pii> Q;
	Q.push({ i,j });
	while (!Q.empty()) {
		pii cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>N || ny<1 || ny>N) continue;
			if (height[nx][ny] <= h || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}