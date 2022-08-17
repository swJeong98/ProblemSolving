/* BOJ 10800 컬러볼 - 2022.05.21 */
#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

class ball{
	public:
	ll color;
	ll sz;
};

pair<ball,ll> A[200005];
ll sum[200005], sum2[200005], ans[200005];

bool cmp(const pair<ball,ll>& p1, const pair<ball,ll>& p2){
	if(p1.X.sz != p2.X.sz) return p1.X.sz < p2.X.sz;
	return p1.X.color < p2.X.color;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for(int i=0;i<N;i++) {
		cin>>A[i].X.color>>A[i].X.sz;
		A[i].Y = (ll)i;
	}
	sort(A, A+N,cmp);

	ll psum = 0;
	ll preX = -1, preY =-1;
	for(int i=0;i<N;i++){
		ll clr = A[i].X.color,  magnitude = A[i].X.sz;
		ll tmp = 0;
		tmp += psum;
		tmp -= sum[clr];
		tmp -= sum2[magnitude];

		if(preX == clr && preY == magnitude) ans[A[i].Y] = ans[A[i-1].Y];
		else ans[A[i].Y] = tmp;
		psum += magnitude;
		sum[clr] += magnitude;
		sum2[magnitude] += magnitude;
		preX = clr, preY = magnitude;
	}

	for(int i=0;i<N;i++) cout<<ans[i]<<'\n';
	return 0;
}