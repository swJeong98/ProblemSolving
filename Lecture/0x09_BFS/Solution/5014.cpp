/*BOJ 5014번 스타트링크 - 2022.01.10*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int height[1000001];
int F, S, G, U, D;
int dx[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	fill(height + 1, height + F + 1, -1);
	height[S] = 0;
	dx[0] += U;
	dx[1] -= D;

	queue<int> Q;
	Q.push(S);
	while (!Q.empty() && height[G] == -1) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx<1 || nx>F) continue;
			if (height[nx] >= 0) continue;
			height[nx] = height[cur] + 1;
			Q.push(nx);
		}
	}
	if (height[G] == -1) cout << "use the stairs";
	else cout << height[G];
}