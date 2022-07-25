/*BOJ 1026 보물 - 2021.10.12 */
#include <iostream>
#include <algorithm>
using namespace std;

int A[50];
int B[50];

int main()
{
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", B + i);
	}

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	int res = 0;

	for (int i = 0; i < N; i++) {
		res += A[i] * B[i];
	}
	printf("%d", res);
}