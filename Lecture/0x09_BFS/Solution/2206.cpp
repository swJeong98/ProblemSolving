/*BOJ 2206번 벽 부수고 이동하기- 2022.01.11*/

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define H get<0>
#define X get<1>
#define Y get<2>
#define TI tuple<int, int, int>
using namespace std;

char board[1002][1002];
int dist[2][1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//dist배열 초기화
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N + 2; j++) fill(dist[i][j], dist[i][j] + M + 2, -1);
	}
	//Input
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	/*시작점에 대한 처리*/
	dist[0][1][1] = dist[1][1][1] = 1;
	queue<TI> Q;
	Q.push({ 0,1,1 });

	/*Do BFS*/
	while (!Q.empty()) {
		TI cur = Q.front(); Q.pop();
		if (X(cur) == N && Y(cur) == M) {
			cout << dist[H(cur)][N][M];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = X(cur) + dx[dir];
			int ny = Y(cur) + dy[dir];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;
			if (board[nx][ny] == '0' && dist[H(cur)][nx][ny] == -1) {
				dist[H(cur)][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1;
				Q.push({ H(cur),nx,ny });
			}
			if (!H(cur) && board[nx][ny] == '1' && dist[1][nx][ny] == -1) {
				dist[1][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1;
				Q.push({ 1,nx,ny });
			}
		}
	}
	cout << -1;
}