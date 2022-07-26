/* BOJ 11000 강의실 배정 - 2022.07.26 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    if(p1.X != p2.X) return p1.X < p2.X;
    return p1.Y < p2.Y;
}

class comp{
public:
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2){
        if(p1.Y != p2.Y) return p1.Y > p2.Y;
        return p1.X < p2.X;
    }    
};

pair<int,int> A[200005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;
    sort(A, A+N, cmp);

    int ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq; //Customizing Heap
    for(int i=0;i<N;i++){
        auto cur = A[i];
        while(!pq.empty() && pq.top().Y <= cur.X) pq.pop();
        pq.push(cur);
        ans = max(ans, (int)pq.size());
    }
    cout<<ans;
    return 0;
}