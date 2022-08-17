/*BOJ 12904번 A와 B - 2022.01.13*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S, T; cin >> S >> T;
	deque<char> dq1, dq2;
	for (char& c : S) dq1.push_back(c);
	for (char& c : T) dq2.push_back(c);

	bool isReverse = false;
	while (dq1.size() < dq2.size()) {
		if (!isReverse) {
			if (dq2.back() == 'A') dq2.pop_back();
			else { //dq2.back()=='B'
				dq2.pop_back();
				isReverse = !isReverse;
			}
		}
		else {
			if (dq2.front() == 'A') dq2.pop_front();
			else {
				dq2.pop_front();
				isReverse = !isReverse;
			}
		}
	}
	while (!dq1.empty() && !dq2.empty()) {
		char c1, c2;
		if (isReverse) {
			c1 = dq1.front(); dq1.pop_front();
			c2 = dq2.back(); dq2.pop_back();
			if (c1 != c2) {
				cout << 0;
				return 0;
			}
		}
		else {
			c1 = dq1.front(); dq1.pop_front();
			c2 = dq2.front(); dq2.pop_front();
			if (c1 != c2) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}