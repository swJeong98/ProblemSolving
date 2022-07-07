/*BOJ 10866번 덱 - 2022.01.03*/

#include <iostream>
#define MAX 10005
using namespace std;

int dat[2*MAX+1];
int head = MAX, tail = MAX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

int empty() {
	if (tail - head == 0) return 1;
	else return 0;
}

int pop_front() {
	if (empty()) return -1;
	else return dat[head++];
}

int pop_back() {
	if (empty()) return -1;
	else return dat[--tail];
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
		if (command == "push_front") {
			int x; cin >> x;
			push_front(x);
		}
		else if (command == "push_back") {
			int x; cin >> x;
			push_back(x);
		}
		else if (command == "pop_front") cout << pop_front() << "\n";
		else if (command == "pop_back") cout << pop_back() << "\n";
		else if (command == "size") cout << size() << "\n";
		else if (command == "empty") cout << empty() << "\n";
		else if (command == "front") cout << front() << "\n";
		else cout << back() << "\n";
	}
}