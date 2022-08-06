#include <iostream>
#define INF 2000
using namespace std;
 
int D[101][101]; 

int main()
{
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> D[i][j];
			if (D[i][j] == 0) D[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] == INF) {
				printf("%d ", 0);
			}
			else {
				printf("%d ", 1);
			}
		}
		printf("\n");
	}
}