/* BOJ 7785 회사에 있는 사람 - 2022.07.27 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N; cin>>N;
	unordered_map<string, bool> s;

	for(int i=0;i<N;i++){
		string name; cin>>name;
		string state; cin>>state;
		if(state == "enter") s[name] = true;
		else s[name] = false;
	}

	vector<string> res;
	for(auto elem : s){
		if(!elem.second) continue;
		res.push_back(elem.first);
	}
	sort(res.begin(), res.end(), greater<string>());
	for(auto elem : res) cout<<elem<<'\n';
	return 0;
}