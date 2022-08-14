/* BOJ 2170 선 긋기 - 2022.08.14 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int,int> A[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;
    sort(A, A+N);

    int ans = 0;
    int st = A[0].X, en = A[0].Y;
    ans += (en - st);
    for(int i=1;i<N;i++){
        if(en >= A[i].Y) continue;
        if(en <= A[i].X) st = A[i].X;
        else st = en;

        en = A[i].Y;
        ans += (en - st);
    }
    cout<<ans;
    return 0;
}
