/* BOJ 16401 과자 나눠주기 - 2022.07.26 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll M, N;
ll A[1000005];

bool check(ll x){
    int cnt = 0;
    for(int i=0;i<N;i++){
        cnt += (A[i]/x);
    }
    return cnt>=M;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>M>>N;
    ll mx = -1;
    for(int i=0;i<N;i++) {
        cin>>A[i];
        mx = max(mx, A[i]);
    }

    ll lo = 0, hi = mx+1;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo;
    return 0;
}