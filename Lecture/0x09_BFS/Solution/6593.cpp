/*BOJ 6593번 상범 빌딩 - 2022.01.10*/

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define TI tuple<int,int,int>
#define H get<0>
#define X get<1>
#define Y get<2>
using namespace std;

char buliding[32][32][32];
int dist[32][32][32];
int dh[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,0,-1,0 };
int dy[6] = { 0,0,0,1,0,-1 };
int L, R, C;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		/*Initialization*/
		for (int i = 0; i < L + 2; i++) {
			for (int j = 0; j < R + 2; j++) {
				fill(dist[i][j], dist[i][j] + C + 2, -1);
			}
		}
		for (int i = 0; i < L + 2; i++) {
			for (int j = 0; j < R + 2; j++) {
				fill(buliding[i][j], buliding[i][j] + C + 2, '\0');
			}
		}
		/*Input*/
		queue<TI> Q;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					cin >> buliding[i][j][k];
					if (buliding[i][j][k] == 'S') {
						dist[i][j][k] = 0;
						Q.push({ i,j,k });
					}
				}
			}
		}
		/*Do BFS*/
		int ans = 0;
		bool isExit = false;
		while (!Q.empty() && !isExit) {
			TI cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nh = H(cur) + dh[dir];
				int nx = X(cur) + dx[dir];
				int ny = Y(cur) + dy[dir];
				if (nh<1 || nh>L || nx<1 || nx>R || ny<1 || ny>C) continue;
				if (buliding[nh][nx][ny] == '#') continue;
				if (dist[nh][nx][ny] >= 0) continue;
				if (buliding[nh][nx][ny] == 'E') {
					isExit = true;
					ans = dist[H(cur)][X(cur)][Y(cur)] + 1;
					break;
				}
				dist[nh][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1;
				Q.push({ nh,nx,ny });
			}
		}
		if (isExit) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}