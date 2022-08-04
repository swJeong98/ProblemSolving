/* BOJ 1806 부분 합 - 2022.08.04 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll N, S; cin>>N>>S;
    for(int i=0;i<N;i++) cin>>A[i];

    int l = 0, r = 0;
    int ans = 1e5 + 10;
    ll sum = A[0];

    while(r <= N-1){
        if(sum < S){
            r += 1;
            sum += A[r];
        }
        else{
            ans = min(ans, r - l + 1);
            sum -= A[l];
            l += 1;
        }
    }
    if(ans == 1e5 + 10) ans = 0;
    cout<<ans;
    return 0;
}
