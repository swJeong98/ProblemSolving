/* BOJ 2467 용액 - 2022.05.01 */
#include <bits/stdc++.h>
using namespace std;

int A[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    int ans0, ans1;
    ans0 = ans1 = 1e9 + 5;
    for(int i=0;i<N;i++){
        int idx = lower_bound(A,A+N,-A[i]) - A;
        
        //idx-1 체크
        if(idx != 0 && idx-1 != i && abs(ans0+ans1) > abs(A[i]+A[idx-1])) {ans0 = A[i], ans1= A[idx-1];}
        //idx 체크
        if(idx < N && idx != i && abs(ans0+ans1) > abs(A[i]+A[idx])) {ans0 = A[i], ans1= A[idx];}
        //idx + 1 체크
        if(idx+1 < N && idx+1 != i && abs(ans0+ans1) > abs(A[i]+A[idx+1])) {ans0 = A[i], ans1= A[idx+1];};
    }
    cout<<min(ans0,ans1)<<' '<<max(ans0,ans1);
}