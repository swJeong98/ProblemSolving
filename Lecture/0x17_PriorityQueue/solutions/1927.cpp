/* BOJ 1927 최소 힙 - 2021.11.28 */
#include <iostream>
#include <queue>
using namespace std;

int NUM[100000];

int main()
{
	priority_queue<int> pq;
	int N; cin >> N;
	int X;
	for (int i = 0; i < N; i++) {
		cin >> X;
		NUM[i] = X;
	}

	for (int i = 0; i < N; i++) {
		X = NUM[i];
		if (!X) {
			if (!pq.empty()) {
				printf("%d\n", -pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
		else {
			pq.push(-X);
		}
	}
}