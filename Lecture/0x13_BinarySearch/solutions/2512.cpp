/* BOJ 2512 예산 - 2022.05.24 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[10005];
ll N, M;

bool check(ll x){
	ll sum = 0;
	for(int i=0;i<N;i++){
		if(A[i] > x){
			sum += x;
		}
		else sum += A[i];
	}
	return sum <= M; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	ll sum = 0, mx = -1;
	for(int i=0;i<N;i++) {
		cin>>A[i];
		mx = max(mx, A[i]);
		sum += A[i];
	}

	cin>>M;
	if(sum <= M){
		cout<<mx;
		return 0;
	}

	ll lo = 0, hi = mx;
	while(lo + 1 < hi){
		ll mid = (lo+hi)/2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout<<lo;
	return 0;
}
