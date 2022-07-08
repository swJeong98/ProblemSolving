/*BOJ 7562 나이트의 이동 - 2022.01.08*/

#include <iostream>
#include <queue>
#include <algorithm>
#define PI pair<int,int>
#define X first
#define Y second
using namespace std;

int T, L;
int board[302][302];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2, -2,-1,1,2,2,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> L;

		for (int i = 0; i < L + 2; i++) fill(board[i], board[i] + L + 2, -1);
		int a, b;
		cin >> a >> b;

		queue<PI> Q;
		Q.push({ a + 1,b + 1 });
		board[a + 1][b + 1] = 0;

		PI dest;
		cin >> a >> b;
		dest.X = a + 1; dest.Y = b + 1;

		while (!Q.empty()) {
			PI cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx<1 || nx>L || ny<1 || ny>L) continue;
				if (board[nx][ny] >= 0) continue;
				board[nx][ny] = board[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
				if (nx == dest.X && ny == dest.Y) break;
			}
		}
		//정답 출력
		cout << board[dest.X][dest.Y] << '\n';
	}
}