#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	int ans = 0;
	while (N--) {
		string s; cin >> s;
		stack<char> st;
		for (char& c : s) {
			if (st.empty()) st.push(c);
			else if (st.top() == c) st.pop();
			else st.push(c);
		}
		if (st.empty()) ans++;
	}
	cout << ans;
}