/* BOJ 14921 용액 합성하기 - 2022.05.04 */
#include <bits/stdc++.h>
using namespace std;

int A[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    int ans = 2e8 + 5;
    for(int i=0;i<N;i++){
        int idx = lower_bound(A,A+N,-A[i]) - A;

        if(idx>0 && idx-1 != i && abs(A[i]+A[idx-1]) < abs(ans)){
            ans = A[i]+A[idx-1];
        }
        if(idx < N && idx != i && abs(A[i]+A[idx]) < abs(ans)){
            ans = A[i]+A[idx];
        }
        // if(idx+1 < N && idx+1 != i && abs(A[i]+A[idx+1]) < abs(ans)){
        //     ans = A[i] + A[idx+1];
        // }
    }
    cout<<ans;
}