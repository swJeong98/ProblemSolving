/* BOJ 2003 수들의 합 2 - 2023.01.10 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;

    vector<int> v(N+1);
    for(int i=0;i<N;i++) cin>>v[i];

    int l=0, r=0;
    int sum = v[l];
    int ans = 0;
    while(r < N) {
        if(sum < M) {
            r++;
            sum += v[r];
        }else if(sum == M) {
            ans++;
            if(l == r) {l++; r++; sum = v[r];}
            else{
                sum -= v[l];
                l++;
            }
        }else{
            if(l == r) {l++; r++; sum = v[r];}
            else{
                sum -= v[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}