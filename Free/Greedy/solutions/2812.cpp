/* BOJ 2812 크게 만들기 - 2022.05.26 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K; cin>>N>>K;
	string s; cin>>s;

	stack<char> st;
	int cnt = 0;
	for(int i=0;i<N;i++){
		char cur = s[i];
		while(!st.empty() && st.top() < cur && cnt < K){
			st.pop();
			cnt++;
		}
		st.push(cur);
	}
	
	while(cnt < K){
		st.pop();
		cnt++;
	}

	vector<char> v;
	while(!st.empty()){
		v.push_back(st.top());
		st.pop();
	}
	for(auto it=v.rbegin(); it!=v.rend(); it++) cout<<*it;
	return 0;
}