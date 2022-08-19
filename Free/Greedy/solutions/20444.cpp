/* BOJ 20444 Project Teams - 2022.08.19 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    vector<int> v(2*N, 0);
    for(int i=0;i<2*N;i++) cin>>v[i];

    sort(v.begin(), v.end());
    int mn = 1e6;

    for(int i=0;i<N;i++){
        int val1 = v[i];
        int val2 = v[2*N-1-i];
        mn = min(mn, val1+val2);
    }
    cout<<mn;

    return 0;
}
