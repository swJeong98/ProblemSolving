/**
 * BOJ 11659 구간합 구하기 4 - 2023.01.19
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100005], pref[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        pref[i] = pref[i-1] + A[i];
    }

    while(M--) {
        int a, b; cin>>a>>b;
        if(a == b) cout<<A[a]<<'\n';
        else cout<<pref[b] - pref[a-1]<<'\n';
    }
    return 0;
}