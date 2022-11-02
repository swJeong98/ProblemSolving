/*BOJ 4949번 균형잡힌 세상 - 2022.01.04*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string s; getline(cin, s);
		if (s == ".") break;

		stack<char> st;
		for (char& c : s) {
			if (c == '[' || c == ']' || c == '(' || c == ')') {
				if (st.empty()) st.push(c);
				else if (st.top() == '(') {
					if (c == ')') st.pop();
					else st.push(c);
				}
				else if (st.top() == '[') {
					if (c == ']') st.pop();
					else st.push(c);
				}
				else { //st.top() ==']' || st.top()==')'
					st.push(c);
				}
			}
		}
		if (st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}