#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int arr[100001];

int main()
{
	int n; cin >> n;
	stack<int> st;  queue<char> res;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int max = arr[1]; 
	for (int i = 1; i <= max; i++) { st.push(i); res.push('+'); }
	st.pop(); res.push('-');

	for (int i = 2; i <= n; i++) {
		if (max > arr[i]) {
			if (st.top() == arr[i]) { st.pop(); res.push('-'); }
			else { cout << "NO"; return 0; }
		}
		else {
			for (int j = max+1; j <= arr[i]; j++) {
				st.push(j); res.push('+');
			}
			max = arr[i]; st.pop(); res.push('-');
		}
	}
	
	while (!res.empty()) {
		cout << res.front() << "\n";
		res.pop();
	}
}
