/*BOJ 5430번 AC - 2022.01.03*/

#include <iostream>
#include <deque>
using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--) {

		string p; cin >> p;
		int N; cin >> N;
		bool isError = false;
		bool isReverse = false;
		deque<int> dq;

		/*parsing*/
		if (N) {
			char ch; cin >> ch;
			for (int i = 0; i < N; i++) {
				cin >> arr[i]; dq.push_back(arr[i]);
				cin >> ch;
			}
		}
		else {
			char ch; cin >> ch; cin >> ch;
		}

		/*p에대한 작업*/
		for (char& c : p) {
			if (c == 'R') {
				if (isReverse) isReverse = false;
				else isReverse = true;
			}
			else { // c == 'D'
				if (dq.empty()) {
					isError = true; break;
				}
				else {
					if (isReverse) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		/*결과 출력*/
		if (isError) cout << "error\n";
		else {
			cout << "[";
			if (dq.size()) {
				if (isReverse) {
					while (!dq.empty()) {
						if (dq.size() != 1) cout << dq.back() << ",";
						else cout << dq.back() << "]\n";
						dq.pop_back();
					}
				}
				else {
					while (!dq.empty()) {
						if (dq.size() != 1) cout << dq.front() << ",";
						else cout << dq.front() << "]\n";
						dq.pop_front();
					}
				}
			}
			else cout << "]\n";
		}
	}
}