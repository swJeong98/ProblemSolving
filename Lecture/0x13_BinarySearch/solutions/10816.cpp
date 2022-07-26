/*BOJ 10816 숫자 카드 2 - 2022.03.13*/
#include <bits/stdc++.h>
using namespace std;

int A[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A,A+N);

    int M; cin>>M;
    for(int i=0;i<M;i++){
        int target; cin>>target;
        auto st = lower_bound(A,A+N,target);
        auto en = upper_bound(A,A+N,target);
        cout << en - st << ' ';
    }
    return 0;
}