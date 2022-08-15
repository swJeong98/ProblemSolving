#include <iostream>
#define INF 100000000
using namespace std;

int getMinIdx();
void dijkstra(int);

int weight[1000][1000];
int d[1000];
bool check[1000];
int N, M;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}

	int a, b, w;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		if (w < weight[a - 1][b - 1]) {
			weight[a - 1][b - 1] = w;
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << weight[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cin >> a >> b;
	dijkstra(a-1);
	printf("%d", d[b - 1]);
	//for (int i = 0; i < N; i++) {
	//	printf("%d\t", d[i]);
	//}
}

void dijkstra(int start) {
	for (int i = 0; i < N; i++) {
		d[i] = weight[start][i];
		/*cout << d[i] << " ";*/
	}
	/*cout << endl;*/
	check[start] = true;

	for (int i = 0; i < N - 2; i++) {
		int current = getMinIdx();
		/*cout << "idx : " << current << "\n";*/
		check[current] = true;

		for (int j = 0; j < N; j++) {
			if (!check[j]) {
				if (d[current] + weight[current][j] < d[j]) {
					d[j] = d[current] + weight[current][j];
				}
			}
		}
		//for (int i = 0; i < N; i++) {
		//	cout << d[i] << " ";
		//}
		//cout << endl;
	}
}

int getMinIdx() {
	int min = INF;
	int minIdx = 0;

	for (int i = 0; i < N; i++) {
		if (d[i] < min && !check[i]) {
			min = d[i];
			minIdx = i;
		}
	}
	return minIdx;
}