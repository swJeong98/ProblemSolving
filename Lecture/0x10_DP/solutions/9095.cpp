/*BOJ 9095 1,2,3 더하기 - 2021.11.27 */
#include <iostream>
using namespace std;

int num[12];

int main()
{
	int T; cin >> T;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	for (int i = 0; i < T; i++) {
		int a; cin >> a;
		if (a == 1 || a == 2 || a == 3) {
			printf("%d\n", num[a]);
			continue;
		}

		int n = 4;
		while (n <= a) {
			num[n] = num[n - 3] + num[n - 2] + num[n - 1];
			n++;
		}
		printf("%d\n", num[a]);

	}
	return 0;
}