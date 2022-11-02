/* BOJ 7795 먹을 것인가 먹힐 것인가 - 2022.07.26 */
#include <bits/stdc++.h>
using namespace std;

int A[20005], B[20005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T; cin>>T;
    while(T--){
        int N, M; cin>>N>>M;
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<M;i++) cin>>B[i];
        sort(A, A+N);
        sort(B, B+M);
        int ans = 0;
        for(int i=0;i<N;i++){
            int idx = lower_bound(B, B+M, A[i]) - B;
            idx -= 1;
            if(idx < 0) continue;
            ans += (idx+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}