/* BOJ 13975 파일 합치기 3 - 2022.05.25 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin>>T;
	while(T--){
		int K; cin>>K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int i=0;i<K;i++) {
			int x; cin>>x;
			pq.push(x);
		}
		long long ans = 0;
		while(!pq.empty()){
			if(pq.size() == 1) break;
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			ans += (a+b);
			pq.push(a+b);
		}
		cout<<ans<<'\n';
	}
	return 0;
}