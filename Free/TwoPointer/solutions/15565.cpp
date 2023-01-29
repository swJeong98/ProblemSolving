/* BOJ 15565 귀여운 라이언 - 2022.12.21 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin>>N>>K;

    vector<int> v(N);
    for(int i=0;i<N;i++) cin>>v[i];

    vector<int> idx;
    for(int i=0;i<N;i++) {
        if(v[i] == 1) idx.push_back(i);
    }

    if(idx.size() < K) {
        cout<<-1;
        return 0;
    }

    int ans = idx[K-1] - idx[0] + 1;
    for(int i=1;i<=idx.size()-K;i++){
        ans = min(ans, idx[i+K-1] - idx[i] + 1) ;
    }
    cout<<ans;
    return 0;
}