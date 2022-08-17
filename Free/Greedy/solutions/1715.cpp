/* BOJ 1715 카드 정렬하기 - 2022.05.22 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<int,int> A[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//Min Heap
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	int N; cin>>N;
	for(int i=0;i<N;i++){
		ll x; cin>>x;
		pq.push(x);
	}

	long long ans = 0;
	while(1){
		if(pq.empty() || pq.size() == 1) break;
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		ans += (a+b);
		pq.push(a+b);
	}
	cout<<ans;
	return 0;
}