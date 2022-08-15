/* BOJ 2252 줄 세우기- 2022.06.02 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int In_degree[32005];
int N, M;

void topology_sort(){
    vector<int> res;
    queue<int> Q;
    for(int i=1;i<=N;i++){
        if(In_degree[i] == 0) Q.push(i);
    }

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        res.push_back(cur);
        for(int nxt : adj[cur]){
            In_degree[nxt]--;
            if(In_degree[nxt] == 0) Q.push(nxt);
        }
    }

    if(res.size() != N) return;
    for(auto elem : res) cout<<elem<<' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        In_degree[b]++;
    }        
    topology_sort();
    return 0;
}