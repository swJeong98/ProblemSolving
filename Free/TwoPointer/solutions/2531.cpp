/* BOJ 2531 회전초밥 - 2022.09.01 */
#include <bits/stdc++.h>
using namespace std;

int A[30005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, d, k, c; cin>>N>>d>>k>>c;
    for(int i=0;i<N;i++) cin>>A[i];

    int ans = -1;
    map<int, int> mp;
    for(int i=0;i<N;i++){
        if(i == 0){
            for(int t=0;t<k;t++) mp[A[t]] += 1;
            int tmp = (int)mp.size();
            if(mp.find(c) == mp.end()) tmp += 1;
            ans = max(ans, tmp);
        }
        else {
            mp[A[i - 1]] -= 1;
            if (mp[A[i - 1]] <= 0) mp.erase(A[i - 1]);
            mp[ A[(i + k-1) % N] ] += 1;

            int tmp = (int) mp.size();
            if (mp.find(c) == mp.end()) tmp += 1;
            ans = max(ans, tmp);
        }
    }
    cout<<ans;
    return 0;
}