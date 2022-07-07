/*BOJ 2493번 탑  - 2021.12.30*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int, int>> st;
	st.push(make_pair(100000001, 0));

	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		while (st.top().first < a) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push(make_pair(a, i));
	}
}
