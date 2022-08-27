/* BOJ 2036 수열의 점수 - 2022.08.27 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    if(N == 1) {
        int x; cin>>x;
        cout<<x; return 0;
    }

    vector<ll> minus, zero, plus;

    for(int i=0;i<N;i++){
        ll x; cin>>x;
        if(x < 0) minus.push_back(x);
        else if(x == 0) zero.push_back(x);
        else plus.push_back(x);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), greater<ll>());

    ll ans = 0;
    int mSize = (int)minus.size();
    int en = (mSize % 2 == 1) ? mSize-2 : mSize-1;
    if(mSize == 0) {} // do nothing
    else if(mSize == 1) ans = (zero.empty()) ? ans + minus[0] : ans;
    else{
        for(int i=0; i<=en; i+=2) ans += minus[i] * minus[i+1];
        if(en == mSize-2 && zero.empty()) ans += minus[mSize-1];
    }

    int pSize = (int)plus.size();
    if(pSize == 0) {} //do nothing
    else if(pSize == 1) ans += plus[0];
    else{
        en = (pSize % 2 == 1) ? pSize-2 : pSize-1;
        bool check = false;
        for(int i=0; i<=en; i+=2){
            ll a = plus[i], b = plus[i+1];
            if(a != 1LL && b != 1LL) ans += a * b;
            else if(a != 1LL) { ans += (ll)(a + pSize - (i+1) ); check = true; break; }
            else { ans += (ll)(pSize - i); check = true; break; }
        }
        if(en == pSize - 2 && !check) ans += plus[pSize-1];
    }
    cout<<ans;
    return 0;
}
