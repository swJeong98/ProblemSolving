/* BOJ 1781 컵라면  - 2022.07.22 */
#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

pair<ll,int> A[200005];

bool cmp(const pair<ll,int>& p1, const pair<ll,int>& p2){
    if(p1.Y != p2.Y) return p1.Y < p2.Y;
    return p1.X < p2.X;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i].Y>>A[i].X;
    }
    sort(A, A+N, cmp);

    priority_queue<pair<ll,int>> pq;
    int limit = 200000;
    int idx = N-1;
    int cur = A[N-1].Y;

    ll ans = 0;
    while(limit){
        while(idx >= 0 && cur >= limit){
            pq.push(A[idx]);
            idx -= 1;
            if(idx < 0) break;
            cur = A[idx].Y;
        }
        limit--;
        if(pq.empty()) continue;
        // cout<<pq.top().X<<endl;
        ans += pq.top().X;
        pq.pop();    
    }
    cout<<ans;
    return 0;
}