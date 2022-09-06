/* BOJ 20922 겹치는 건 싫어 - 2022.09.05 */
#include <bits/stdc++.h>
using namespace std;

int A[200005], freq[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>A[i];

    int l = 0, r = 0;
    int ans = 0, len = 0;
    while(r < N){
        if(freq[A[r]] < K){
            len += 1;
            freq[A[r]] += 1;
            ans = max(ans, len);
            r += 1;
        }
        else{
            while(A[l] != A[r]) {freq[A[l++]] -= 1; len -= 1;}
            if(l == r) len = 1;
            else{
                l += 1;
                len = r - l + 1;
            }
            ans = max(ans, len);
            r += 1;
        }
    }
    cout<<ans;
    return 0;
}
