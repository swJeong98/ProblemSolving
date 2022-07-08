/*BOJ 5427번 불 - 2022.01.08*/

#include <iostream>
#include <queue>
#include <algorithm>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

char board[1002][1002];
int dist[1002][1002];
int SK[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int T, N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> M >> N;
		for (int i = 0; i < N + 2; i++) fill(dist[i], dist[i] + M + 2, -1);
		for (int i = 0; i < N + 2; i++) fill(SK[i], SK[i] + M + 2, -1);

		queue<PI> Q1, Q2;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> board[i][j];

				if (board[i][j] == '@') {
					SK[i][j] = 0;
					Q2.push({ i,j });
				}

				if (board[i][j] == '*') {
					dist[i][j] = 0;
					Q1.push({ i,j });
				}
			}
		}

		//불에 대한 BFS
		while (!Q1.empty()) {
			PI cur = Q1.front(); Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx<1 || nx>N || ny<1 || ny>M) continue;
				if (board[nx][ny] == '#' || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q1.push({ nx,ny });
			}
		}

		//상근이에 대한 BFS
		bool isExit = false;
		while (!Q2.empty()) {
            if(isExit) break;
			PI cur = Q2.front(); Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx<1 || nx>N || ny<1 || ny>M) {
					cout << SK[cur.X][cur.Y] + 1 << "\n";
					isExit = true;
					break;
				}
				if (board[nx][ny] == '#' || SK[nx][ny] >= 0) continue;
				if (dist[nx][ny] != -1 && dist[nx][ny] - SK[cur.X][cur.Y] <= 1) continue;
				SK[nx][ny] = SK[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
		}
		if (!isExit) cout << "IMPOSSIBLE\n";
	}
}