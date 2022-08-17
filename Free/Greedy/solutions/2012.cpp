/*BOJ 2012 등수 매기기 - 2021.10.02 */
#include <iostream>
#include <algorithm>
using namespace std;

int prediction[500000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", prediction + i);
	}

	//학생들이 적어낸 등수와 최대한 일치시키기 위해 정렬 수행.
	sort(prediction, prediction + N);

	int diff = 0; long long sum = 0;
	for (int i = 0; i < N; i++) {
		diff = abs(prediction[i] - (i + 1));
		sum += (long long)diff;
	}
	cout << sum;
}