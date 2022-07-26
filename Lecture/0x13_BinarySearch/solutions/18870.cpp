/*BOJ 18870번 좌표 압축 - 2022.01.04*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> NUMS[1000000];
vector<int> res(1000000);

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		NUMS[i].first = i;
		cin >> NUMS[i].second;
	}

	sort(NUMS, NUMS + N, cmp);

	pair<int,int> cur;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cur.first = i;
			cur.second = NUMS[i].second;
			res[NUMS[i].first] = i;
		}
		else {
			if (cur.second == NUMS[i].second) {
				res[NUMS[i].first] = cur.first;
			}
			else {
				cur.first += 1;
				cur.second = NUMS[i].second;
				res[NUMS[i].first] = cur.first;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";
	}
}