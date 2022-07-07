#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	string str;
	while (T--) {
		cin >> str;

		list<char> password;
		list<char>::iterator cur = password.begin();

		for (char& c : str) {
			if (c == '<') {
				if (cur != password.begin()) cur--;
			}
			else if (c == '>') {
				if (cur != password.end()) cur++;
			}
			else if (c == '-') {
				if (cur != password.begin()) {
					cur--;
					cur = password.erase(cur);
				}
			}
			else {
				password.insert(cur, c);
			}
		}

		for (char& c : password) cout << c;
		cout << "\n";
	}
}