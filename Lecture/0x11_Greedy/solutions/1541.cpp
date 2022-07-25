/*BOJ 1541번 잃어버린 괄호 - 2022.01.04*/

#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	char op = '*'; // '+' or '-' 둘다 아닌 상태를 의미.
	int len = 0;
	int ans = 0;
	int t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			len++;
		}
		else if (s[i] == '+') {
			t = atoi(&s[i - len]);
			len = 0;

			if (op == '*') {
				op = '+';
				ans += t;
				continue;
			}
			if (op == '+') {
				ans += t;
			}
			else { //op=='-'
				ans -= t;
			}
		}
		else { //s[i] == '-'
			t = atoi(&s[i - len]);
			len = 0;

			if (op == '*') {
				op = '-';
				ans += t;
				continue;
			}
		    if (op == '-') {
				ans -= t;
			}
			else { //op =='+'
				ans += t;
				op = '-';
			}
		}
	}
	t = atoi(&s[s.size() - len]);
	if (op == '+') ans += t;
	else if (op == '-') ans -= t;
	else ans += t;
	cout << ans;
}