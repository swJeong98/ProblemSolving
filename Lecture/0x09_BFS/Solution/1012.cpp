/*BOJ 1012번 유기농 배추 - 2022.01.07*/

#include <iostream>
#include <algorithm>
#include <queue>
#define PI pair<int,int> 
#define X first
#define Y second
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int territory[52][52];
bool visit[52][52];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int M, N, K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int i = 0; i < N + 2; i++) fill(territory[i], territory[i] + M + 2, 0);
		for (int i = 0; i < N + 2; i++) fill(visit[i], visit[i] + M + 2, false);
		
		for (int i = 0; i < K; i++) {
			int x; cin >> x;
			int y; cin >> y;
			territory[y + 1][x + 1] = 1;
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visit[i][j] && territory[i][j] == 1) {
					ans++;
					queue<PI> Q;
					Q.push({ i,j });
					visit[i][j] = true;
					while (!Q.empty()) {
						PI cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx<1 || nx>N || ny<1 || ny>M) continue;
							if (visit[nx][ny] || territory[nx][ny] == 0) continue;
							visit[nx][ny] = true;
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}