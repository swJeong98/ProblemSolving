/*BOJ 2178번 미로탐색 - 2022.01.05*/

#include <iostream>
#include <queue>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

int maze[102][102];
bool visit[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			maze[i + 1][j + 1] = s[j] - '0';
		}
	}
	//do BFS
	queue<PI> q;
	q.push({ 1,1 });
	visit[1][1] = true;
	while (!q.empty()) {
		PI cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;
			if (visit[nx][ny] || maze[nx][ny] == 0) continue;
			visit[nx][ny] = true;
			maze[nx][ny] = maze[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	cout << maze[N][M];
}