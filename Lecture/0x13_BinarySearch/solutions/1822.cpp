/* BOJ 1822 차집합 - 2022.07.26 */
#include <bits/stdc++.h>
using namespace std;

int A[500005], B[500005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    sort(A, A+N);
    sort(B, B+M);

    vector<int> res;
    for(int i=0;i<N;i++){
        int cur = A[i];
        int tot = upper_bound(B,B+M,cur) - lower_bound(B,B+M,cur);
        if(tot == 0) res.push_back(cur);
    }
    cout<<res.size()<<'\n';
    for(auto elem : res) cout<<elem<<" ";
    return 0;
}