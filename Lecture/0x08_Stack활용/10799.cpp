/*BOJ 10799번 쇠막대기 (stack활용)  - 2021.12.31*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	stack<char> st;
	char latest;
	int ans = 0;

	st.push('(');
	int size = str.size();
	for (int i = 1; i < size; i++) {
		latest = str[i - 1];

		if (str[i] == '(') st.push('(');
		if (str[i] == ')') {
			if (latest == ')') {
				ans++;
				st.pop();
			}
			else {
				st.pop();
				ans += st.size();
			}
		}
	}
	ans += st.size();
	cout << ans;
}