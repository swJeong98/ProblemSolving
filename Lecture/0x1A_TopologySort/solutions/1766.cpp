/* BOJ 1766 문제집 - 2022.07.23 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int deg[32005];

void topology_sort(int N){
    priority_queue<int, vector<int>, greater<int>> pq; //Min heap
    vector<int> res;

    for(int i=1;i<=N;i++) {
        if(deg[i] == 0) pq.push(i);
    }
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        res.push_back(cur);

        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) pq.push(nxt);
        }
    }
    for(auto elem : res) cout<<elem<<" ";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }

    topology_sort(N);
    return 0;
}