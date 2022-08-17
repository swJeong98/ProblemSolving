/* BOJ 2109 순회강연 - 2022.07.01 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int,int> A[10005];

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    if(p1.Y != p2.Y) return p1.Y > p2.Y;
    return p1.X > p2.X;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin>>N;
    if(N==0) {cout<<0; return 0;}

    for(int i=1;i<=N;i++) cin>>A[i].X>>A[i].Y;

    sort(A+1, A+N+1, cmp); 
   
    priority_queue<int> pq; //Max Heap
    int ans = 0;
    int cur = 1; 
    for(int day=10000; day>=1; day--){
        while(day == A[cur].Y && cur <= N){
            pq.push(A[cur].X);
            cur++;
        }
        if(pq.empty()) continue;
        ans += pq.top(); pq.pop();
    }
    cout<<ans;
    return 0;
}