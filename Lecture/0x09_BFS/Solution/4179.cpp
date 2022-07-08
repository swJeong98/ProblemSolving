/*BOJ 4179번 불! - 2022.01.07*/

#include <iostream>
#include <queue>
#include <algorithm>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

char maze[1002][1002];
int dist[1002][1002];
int JH[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C;

void checkFire();
void checkJH();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R + 2; i++) fill(dist[i], dist[i] + C + 2, -1);
	for (int i = 0; i < R + 2; i++) fill(JH[i], JH[i] + C + 2, -1);
	//불과 지훈이의 초기 위치를 각 큐에 저장.
	queue<PI> q1;
	queue<PI> q2;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'J') {
				q1.push({ i,j });
				JH[i][j] = 0;
			}
			if (maze[i][j] == 'F') {
				q2.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}
	//불에 대한 BFS
	while (!q2.empty()) {
		PI cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>R || ny<1 || ny>C) continue;
			if (maze[nx][ny] == '#' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}
	//지훈이에 대한 BFS
	while (!q1.empty()) {
		PI cur = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>R || ny<1 || ny>C) {
				cout << JH[cur.X][cur.Y] + 1;
				return 0;
			}
			if (JH[nx][ny] >= 0) continue;
			if (maze[nx][ny] == '#') continue;
			if (dist[nx][ny] != -1 && dist[nx][ny] - JH[cur.X][cur.Y] <= 1) continue;
			JH[nx][ny] = JH[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}