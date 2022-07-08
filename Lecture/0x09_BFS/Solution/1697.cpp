/*BOJ 1697번 숨바꼭질 - 2022.01.07*/

#include <iostream>
#include <algorithm>
#include <queue>
#define LIMIT 100001
using namespace std;

int board[LIMIT];
int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	fill(board, board + LIMIT, -1);
	board[N] = 0;
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 0) nx = cur - 1;
			else if (dir == 1) nx = cur + 1;
			else nx = cur * 2;
			if (nx<0 || nx>LIMIT) continue;
			if (board[nx] >= 0) continue;
			board[nx] = board[cur] + 1;
			q.push(nx);
			if (nx == K) {
				cout << board[nx];
				return 0;
			}
		}
	}
}