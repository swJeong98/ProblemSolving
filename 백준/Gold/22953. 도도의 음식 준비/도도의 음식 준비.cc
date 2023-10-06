/* BOJ 22935 도도의 음식 준비 - 2023.10.06*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K, C;
ll ans = 1e15;
ll A[15];

bool check(ll x) {
    if(x == 0) return false;
    ll sum = 0;

    for(int i=0; i<N; i++) {
        ll tmp = max(1LL, A[i]);
        sum += (x / tmp);
    }

    return sum >= K;
}

ll logic() {
    ll lo = 0, hi = 1e13;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}

void dfs(int cnt) {
    if(cnt == C) {
        ans = min(ans, logic());
        return;
    }

    for(int i=0; i<N; i++) {
        A[i] -= 1;
        dfs(cnt+1);
        A[i] += 1;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K>>C;
    for(int i=0; i<N; i++) cin>>A[i];

    dfs(0);

    cout << ans;
    return 0;   
}
