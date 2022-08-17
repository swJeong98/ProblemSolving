/* BOJ 1826 연료 채우기 - 2022.07.04 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<int> tmp_pq;
    int N; cin>>N;
    for(int i=0;i<N;i++){
        int x, y; cin>>x>>y;
        pq.push({x,y});
    }

    int L, P; cin>>L>>P;
    int cnt = 0;
    while(P < L){
        while(!pq.empty() && P >= pq.top().X) {
            tmp_pq.push(pq.top().Y);
            pq.pop();
        }
        if(tmp_pq.empty()){
            cout<<-1;
            return 0;
        }
        int mx = tmp_pq.top();
        tmp_pq.pop();
        P += mx;
        cnt += 1;
    }
    cout<<cnt;
    return 0;
}