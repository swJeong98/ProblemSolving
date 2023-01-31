/**
 * BOJ 10025 게으른 백곰 - 2023.01.30
 */
#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[1000005];
int pref[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=0; i<N; i++) {
        int g, x; cin>>g>>x;
        a[x] = g;
    }

    pref[0] = a[0];
    for(int i=1; i<=1000000; i++) pref[i] = pref[i-1] + a[i];

    int ans = -1;
    for(int i=0; i<=1000000; i++) {
        int l = max(0, i-K);
        int r = min(1000000, i+K);
        if(l == 0) ans = max(ans, pref[r]);
        else ans = max(ans, pref[r] - pref[l-1]);
    }
    cout<<ans;
    return 0;
}