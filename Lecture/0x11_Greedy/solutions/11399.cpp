/*BOJ 11399 ATM- 2022.03.15*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;
    vector<int> v(N+5);
    for(int i=1;i<=N;i++) cin>>v[i];
    sort(v.begin()+1,v.begin()+N+1);

    vector<int> prefix_sum(N+5);
    int cur = 0;
    for(int i=1;i<=N;i++){
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    int ans = 0;
    for(int i=1;i<=N;i++) ans += prefix_sum[i];
    cout<<ans; 
    return 0;
}