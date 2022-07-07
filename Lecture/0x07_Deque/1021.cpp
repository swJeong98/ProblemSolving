/*BOJ 1021번 회전하는 큐  - 2022.01.02*/
/*deque 자료구조의 특징 정리하기.*/

#include <iostream>
#include <deque>
using namespace std;

int pos[50];
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> pos[i];

	deque<int> dq;
	for (int i = 1; i <= N; i++) dq.push_back(i);

	int ans = 0;
	for (int i = 0; i < M; i++) {
		int cur = pos[i];
		int mid = (dq.size() + 1) / 2;
		while (1) {
			//int left = cur - 1;
			//int right = dq.size() - cur + 1;
			if (cur == 1) {
				dq.pop_front();
				cur = 0;
				for (int j = i + 1; j < M; j++) pos[j]--;
			}
			else if (cur <= mid) {
				dq.push_back(dq.front());
				dq.pop_front();
				cur--; ans++;
				for (int j = i + 1; j < M; j++) {
					if (pos[j] == 1) pos[j] = dq.size();
					else pos[j]--;
				}
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
				if (cur == dq.size()) cur = 1;
				else cur++;
				ans++;
				for (int j = i + 1; j < M; j++) {
					if (pos[j] == dq.size()) pos[j] = 1;
					else pos[j]++;
				}
			}
			if (!cur) break;
		}
	}
	cout << ans;
}