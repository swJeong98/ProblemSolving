/* BOJ 2623 음악프로그램  - 2022.07.16 */
#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> adj[1005];
int deg[1005];

void topology_sort(){
    queue<int> q;
    vector<int> result;

    for(int i=1;i<=N;i++){
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);
        
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    if(result.size() == N){
        for(auto elem : result){
            cout<<elem<<'\n';
        }
    }
    else cout<<0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    /* Input */
    for(int i=1;i<=M;i++){
        int x; cin>>x;
        vector<int> tmp;
        for(int j=0;j<x;j++){
            int t; cin>>t;
            tmp.push_back(t);
        }

        int pre = -1;
        for(auto elem : tmp){
            if(pre == -1) pre = elem;
            else{
                adj[pre].push_back(elem);
                pre = elem;
                deg[elem]++;
            }
        }
    }

    /* Topology Sort */
    topology_sort();
    return 0;
}