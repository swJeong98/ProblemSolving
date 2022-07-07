/*BOJ 10845번 큐  - 2022.01.03*/

#include <iostream>
#define MAX 10005
using namespace std;

int dat[MAX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

int empty() {
	if (head == tail) return 1;
	else return 0;
}

void pop() {
	if (empty()) cout << -1 << "\n";
	else cout << dat[head++] << "\n";
}

int size() {
	return tail - head;
}


int front() {
	if (empty()) return -1;
	else return dat[head];
}

int back() {
	if (empty()) return -1;
	else return dat[tail - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	while (N--) {
		string command; cin >> command;
		if (command == "push") {
			int x; cin >> x;
			push(x);
		}
		else if (command == "pop") {
			pop();
		}
		else if (command == "size") {
			cout << size() << "\n";
		}
		else if (command == "empty") {
			cout << empty() << "\n";
		}
		else if (command == "front") {
			cout << front() << "\n";
		}
		else {
			cout << back() << "\n";
		}
	}
}
