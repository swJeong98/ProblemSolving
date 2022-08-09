/* BOJ 7453 합이 0인 네 정수 - 2022.08.09 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[4005], B[4005], C[4005], D[4005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i]>>B[i]>>C[i]>>D[i];

    vector<int> sum1, sum2;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sum1.push_back(A[i] + B[j]);
            sum2.push_back(C[i] + D[j]);
        }
    }
    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    for(auto elem : sum1){
        ans += (ll)( upper_bound(sum2.begin(), sum2.end(), -elem) - lower_bound(sum2.begin(), sum2.end(), -elem) );
    }
    cout<<ans;
    return 0;
}
