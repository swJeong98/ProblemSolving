/* BOJ 13144 List of Unique Numbers - 2022.08.05 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool exist[100005];
int pos[100005], A[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    int l = 0, r = 0;
    ll ans = 0;
    while(r <= N-1){
        if(!exist[A[r]]){
            ans += (ll)(r-l+1);
            exist[A[r]] = true;
            pos[A[r]] = r;
            r += 1;
        }
        else{
            ans += (ll)(r - pos[A[r]]);
            while(l <= pos[A[r]]){
                exist[A[l]] = false;
                l++;
            }
            exist[A[r]] = true;
            pos[A[r]] = r;
            r += 1;
        }
    }
    cout<<ans;
    return 0;
}