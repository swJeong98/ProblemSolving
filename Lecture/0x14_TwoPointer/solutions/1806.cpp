/* BOJ 1806 부분합 - 2022.04.28 */
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_sum(100005);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, S; cin>>N>>S;
    for(int i=1; i<=N; i++){
        int x; cin>>x;
        if(x >= S) {cout<<1; return 0;}
        prefix_sum[i] = prefix_sum[i-1] + x;
    }
    
    int ans = 100005;
    for(int i=1; i<=N; i++){
        int target = S + prefix_sum[i-1];
        auto pos = lower_bound(prefix_sum.begin()+1, prefix_sum.begin()+N+1,target);
        if(pos == prefix_sum.begin()+N+1) continue;
        int dist = (pos - prefix_sum.begin()) - i + 1;
        ans = min(ans,dist);
    }
    if(ans == 100005) cout<<0;
    else cout<<ans;
    return 0;
}
