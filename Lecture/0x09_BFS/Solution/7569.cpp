/*BOJ 7569번 토마토(3차원 BFS) - 2022.01.08*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#define TUPLE_INT tuple<int,int,int>
using namespace std;

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };
int dz[6] = { 1,-1,0,0,0,0 };
int board[102][102][102];
int dist[102][102][102];
int N, M, H;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	queue<TUPLE_INT> Q;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 0) dist[i][j][k] = -1;
				if (board[i][j][k] == 1) Q.push({ i,j,k });
			}
		}
	}
    
	while (!Q.empty()) {
		TUPLE_INT cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nh = get<0>(cur) + dx[dir];
			int nx = get<1>(cur) + dy[dir];
			int ny = get<2>(cur) + dz[dir];
			if (nh<1 || nh>H || nx<1 || nx>N || ny<1 || ny>M) continue;
			if (dist[nh][nx][ny] >= 0) continue;
			dist[nh][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({ nh,nx,ny });
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}