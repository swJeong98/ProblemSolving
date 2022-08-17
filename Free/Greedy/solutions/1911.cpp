/* BOJ 1911 흙길 보수하기 - 2022.08.14 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, L;
pair<int,int> A[10005];

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    if(p1.X != p2.X) return p1.X < p2.X;
    return p1.Y > p2.Y;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>L;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;
    sort(A, A+N, cmp);

    int st= 0, en = 0;
    int ans = 0;

    for(int i=0;i<N;i++){
        if(en >= A[i].Y) continue;
        if(en <= A[i].X) st = A[i].X;
        else st = en;

        int interval = A[i].Y - st;
        int needed = (interval % L == 0) ? (interval/L) : 1+(interval/L);
        ans += needed;
        en = st + needed * L;
    }
    cout<<ans;
    return 0;
}