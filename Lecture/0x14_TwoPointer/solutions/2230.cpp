/* BOJ 2230 수 고르기 - 2022.08.04 */
#include <bits/stdc++.h>
using namespace std;

int A[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;
    if(M==0) {cout<<0; return 0;}
    
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A, A+N);

    int st = 0, en = 0;
    int ans = 2e9+5;
    while(en <= N-1){
        if(A[en] - A[st] < M) en++;
        else {
            ans = min(ans, A[en]-A[st]);
            st++;
        }
    }
    cout<<ans;
    return 0;
}
