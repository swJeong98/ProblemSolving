#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int K; int temp;
	cin >> K;

	stack<int> st;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) {
			st.pop();
		}
		else {
			st.push(temp);
		}
	}

	int res = 0;
	while (!st.empty()) {
		res += st.top(); st.pop();
	}
	cout << res;
}
