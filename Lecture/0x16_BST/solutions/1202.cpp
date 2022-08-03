/* BOJ 1202 보석 도둑 - 2022.07.14 */
#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

pair<ll,ll> A[300005];

bool cmp(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    if(p1.Y != p2.Y) return p1.Y > p2.Y;
    return p1.X < p2.X; 
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    ll N, K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;
    sort(A, A+N, cmp);

    multiset<ll> ms;
    for(int i=0;i<K;i++) {
        ll x; cin>>x;
        ms.insert(x);
    }

    ll ans = 0;
    for(int i=0;i<N;i++){
        ll m = A[i].X, v = A[i].Y;
        if(ms.empty()) break;
        auto it = ms.lower_bound(m);
        if(it == ms.end()) continue;
        ans += v;
        ms.erase(it);
    }
    cout<<ans;
    return 0;
}
