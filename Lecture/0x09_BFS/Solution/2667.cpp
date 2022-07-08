#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int graph[27][27];
void bfs(int, int, int);
vector<int> result;
int N;

int main()
{
	cin >> N;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str; int len = str.length();
		for (int j = 1;j <= len; j++) {
			graph[i][j] = str[j-1] - '0';
		}
	}

	int group = 0, check = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 1) {
				/*printf("%d %d\n", i, j);*/
				group++; check++;
				bfs(i, j, check);
			}
		}
	}
	printf("%d\n", group);
	sort(result.begin(), result.end());
	for (int i = 0; i < group; i++) {
		printf("%d\n", result[i]);
	}
}

void bfs(int i, int j, int check) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	graph[i][j] = check;

	int res = 1;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();

		
		if (graph[i - 1][j] == 1) {
			if (graph[i - 1][j] != check) {
				graph[i - 1][j] = check;
				res++;
			}
			q.push(make_pair(i - 1, j));
		}
		if (graph[i][j - 1] == 1) {
			if (graph[i][j - 1] != check) {
				graph[i][j - 1] = check;
				res++;
			}
			q.push(make_pair(i, j - 1));
		}
		if (graph[i + 1][j] == 1) {
			if (graph[i + 1][j] != check) {
				graph[i + 1][j] = check;
				res++;
			}
			q.push(make_pair(i + 1, j));
		}
		if (graph[i][j + 1] == 1) {
			if (graph[i][j + 1] != check) {
				graph[i][j + 1] = check;
				res++;
			}
			q.push(make_pair(i, j + 1));
		}
		
	}
	result.push_back(res);
}