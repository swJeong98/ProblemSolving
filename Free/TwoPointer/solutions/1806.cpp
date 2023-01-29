/* BOJ 1806 부분합 - 2023.01.10 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll N, S; cin>>N>>S;
    vector<ll> v(N+5);
    for(int i=0;i<N;i++) cin>>v[i];

    ll ans = 1e5 + 5;
    ll st = 0, en = 0;
    ll tot = v[0];

    while(en < N) {
        if(tot < S){
            en++;
            if(en != N) tot += v[en];
        }else{
            ans = min(ans, en - st + 1);
            if(st == en) {
                st++;
                en++;
                tot = v[st];
            }else{
                tot -= v[st];
                st++;
            }
        }
    }

    if(ans == 1e5 + 5) cout<<0;
    else cout<<ans;
    return 0;
}