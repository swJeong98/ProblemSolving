/* BOJ 7453 합이 0인 네 정수 - 2023.01.10 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);

    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }

    vector<int> sumA;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sumA.push_back(A[i] + B[j]);
        }
    }

    vector<int> sumB;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sumB.push_back(C[i] + D[j]);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    ll ans = 0;

    for(const auto& e : sumA) {
        ans += upper_bound(sumB.begin(), sumB.end(), -e) - lower_bound(sumB.begin(), sumB.end(), -e);
    }
    cout<<ans;
    return 0;
}