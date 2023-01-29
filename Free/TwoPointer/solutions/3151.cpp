/* BOJ 3151 합이 0 - 2022.04.28 */
#include <bits/stdc++.h>
using namespace std;

vector<int> A(10005);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    sort(A.begin(),A.begin()+N);
    long long ans = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int cur = A[i]+A[j];
            int pos = j+1;
            int target = -cur;
            auto st = lower_bound(A.begin()+pos,A.begin()+N,target);
            auto en = upper_bound(A.begin()+pos,A.begin()+N,target);
            ans += (en-st);
        }
    }
    cout<<ans;
}