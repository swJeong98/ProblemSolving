#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;

	list<char> List;
	for (char c : s) List.push_back(c);

	list<char>::iterator cursor = List.end();

	int M; cin >> M;
	while (M--) {
		char op; cin >> op;
		if (op == 'P') {
			char add; cin >> add;
			List.insert(cursor, add);
		}
		else if (op == 'L') {
			if (cursor != List.begin()) cursor--;
		}
		else if (op == 'D') {
			if (cursor != List.end()) cursor++;
		}
		else {
			if (cursor != List.begin()) {
				cursor--;
				cursor = List.erase(cursor);
			}
		}
	}
	for (char c : List) cout << c;
}