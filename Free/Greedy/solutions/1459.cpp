/* BOJ 1459 걷기 - 2022.08.17 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll X, Y, W, S; cin>>X>>Y>>W>>S;

    ll val = (2*W > S) ? S : 2*W;
    ll ans = 0;
    ans += val * min(X, Y);

    ll diff = (ll)abs(X - Y);
    ans += ( 2 * (diff/2) * min(W, S));
    if(diff % 2 == 1) ans += W;

    cout<<ans;
    return 0;
}