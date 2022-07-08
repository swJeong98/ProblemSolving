/*BOJ 2538번 영역 구하기 - 2022.01.08*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

int board[102][102];
bool visit[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int M, N, K;
vector<int> res;

void BFS(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> K;
	int a, b, c, d;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c >> d;
		for (int j = a + 1; j <= c; j++) {
			for (int k = b + 1; k <= d; k++) {
				board[j][k] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visit[i][j] && board[i][j] == 0) {
				ans++;
				BFS(i, j);
			}
		}
	}
	sort(res.begin(), res.end());
	cout << ans << "\n";
	for (auto a : res) {
		cout << a << " ";
	}
}

void BFS(int x, int y) {
	queue<PI> Q;
	Q.push({ x,y });
	visit[x][y] = true;
	int area = 0;
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		area++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;
			if (visit[nx][ny] || board[nx][ny] == 1)continue;
			Q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
	res.push_back(area);
}