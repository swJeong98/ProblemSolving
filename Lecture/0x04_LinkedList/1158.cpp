#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	list<int> person;
	for (int i = 1; i <= N; i++) person.push_back(i);

	cout << "<";
	list<int>::iterator cur = person.begin();

	while (person.size()) {
		for (int i = 0; i < K - 1; i++) {
			if (cur == --person.end()) cur = person.begin();
			else cur++;
		}

		if (person.size() != 1) cout << *cur << ", ";
		else cout << *cur;

		cur = person.erase(cur);
		if (cur == person.end()) cur = person.begin();
	}
	cout << ">";
}