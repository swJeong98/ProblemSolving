#include <iostream>
#define MAX 10000
using namespace std;


class IntStack {
public:
	int stk[MAX] = { 0 };
	size_t size = 0;
public:
	void push(int X) {
		if (!isFull()) {
			stk[size++] = X;
		}
		//cout << "size : " << size << "\n";
	}
	void pop() {
		if (size == 0) cout << -1 << "\n";
		else cout << stk[--size] << "\n";
		//cout << "size : " << size << "\n";
	}
	void getSize() {
		cout << size << "\n";
	}
	void isEmpty() {
		if (size == 0) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	void top() {
		if (size == 0) cout << -1 << "\n";
		else { cout << stk[--size] << "\n"; size++; }
		//cout << "size : " << size << "\n";
	}
	bool isFull() {
		return size > MAX;
	}
};

int main()
{
	int N;
	cin >> N;

	IntStack st;
	string command;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			int operand; cin >> operand;
			st.push(operand);
		}
		else if (command == "pop") {
			st.pop();
		}
		else if (command == "size") {
			st.getSize();
		}
		else if (command == "empty") {
			st.isEmpty();
		}
		else {
			st.top();
		}
	}
}
