/* BOJ 11501 주식 - 2022.07.25 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        for(int i=0;i<N;i++) cin>>A[i];

        ll mx = A[N-1];
        ll ans = 0;
        for(int i=N-2;i>=0;i--){
            ll cur = A[i];
            if(mx >= cur) ans += (mx - cur);
            else mx = cur;
        }
        cout<<ans<<'\n';
    }
    return 0;
}