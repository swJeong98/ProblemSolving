/*BOJ 10026번 적록색약 - 2022.01.07*/

#include <iostream>
#include <queue>
#include <algorithm>
#define PI pair<int,int> 
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Grid[102][102];
bool visit[102][102];
int N;

void BFS(int x, int y);
void BFS2(int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'R') Grid[i + 1][j + 1] = 0;
			else if (s[j] == 'G') Grid[i + 1][j + 1] = 1;
			else Grid[i + 1][j + 1] = 2;
		}
	}
	//적록색약이 아닌 경우에 대한 BFS
	int ans1 = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				ans1++;
				BFS(i, j);
			}
		}
	}
	
	//적록색약 환자의 경우에 대한 BFS
	int ans2 = 0;
	for (int i = 0; i < N + 2; i++) fill(visit[i], visit[i] + N + 2, false);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Grid[i][j] == 0) Grid[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				ans2++;
				BFS(i, j);
			}
		}
	}
	//정답 출력
	cout << ans1 << " " << ans2;
}

void BFS(int x, int y) {
	queue<PI> Q;
	visit[x][y] = true;
	Q.push({ x,y });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || nx>N || ny<1 || ny>N) continue;
			if (visit[nx][ny] || Grid[nx][ny] != Grid[x][y]) continue;
			visit[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}