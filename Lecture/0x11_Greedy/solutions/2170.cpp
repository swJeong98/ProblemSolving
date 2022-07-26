/* BOJ 2170 선 긋기 - 2022.07.26 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int,int> A[1000005];

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    if(p1.X != p2.X) return p1.X < p2.X;
    return p1.Y < p2.Y;
}

bool disjoint(const pair<int,int>& p1, const pair<int,int>& p2){
    return p1.X > p2.Y || p1.Y < p2.X;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;
    sort(A, A+N, cmp);

    int ans = 0;
    int st = A[0].X;
    int en = A[0].Y;
    for(int i=1;i<N;i++){
        if(disjoint({st,en}, A[i])){
            ans += (en - st);
            st = A[i].X, en = A[i].Y;
        }
        else en = max(en, A[i].Y);
    }
    ans += (en - st);
    cout<<ans;
    return 0;
}
