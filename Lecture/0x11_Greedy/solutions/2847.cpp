/* BOJ 2847 게임을 만든 동준이 - 2022.07.25 */
#include <bits/stdc++.h>
using namespace std;

int A[105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    int limit = A[N-1];
    int ans = 0;
    for(int i=N-2;i>=0;i--){
        limit--;
        int cur = A[i];
        if(limit <= cur) ans += (cur-limit);
        else limit = cur;
    }
    cout<<ans;
    return 0;
}