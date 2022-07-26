/* BOJ 1477 휴게소 세우기 - 2022.05.19 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,M,L;
ll A[55];

bool check(ll x){
    ll cnt = 0, pre = 0;
    if(x == 0) return false;
    for(int i=0;i<N;i++){
        ll dist = A[i] - pre;
        ll val = dist/x, mod = dist%x;
        if(val > 0 && mod != 0) cnt += val;
        if(val > 0 && mod == 0) cnt += (val-1);
        pre = A[i];
    }
    ll dist = L - A[N-1];
    ll val = dist/x, mod = dist % x;
    if(val > 0 && mod != 0) cnt += val;
    if(val > 0 && mod == 0) cnt += (val-1);
    return cnt <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin>>N>>M>>L;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A,A+N);

    ll lo = 0, hi = L;
    while(lo + 1 < hi){
        ll mid = (lo + hi)/2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
	return 0;
}