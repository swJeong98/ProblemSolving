/* BOJ 14267 회사 문화 1 - 2022.05.12 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int w[100005];
int ans[100005];

void dfs(int src){
    int child = 0;
    for(int i : adj[src]){
        if(src < i) child++;
    }
    //Leaf Node
    if(child == 0) return;

    for(int i : adj[src]){
        if(src < i){
            w[i] += w[src];
            dfs(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        if(i == 1) continue;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    for(int i=0;i<M;i++){
        int src, x; cin>>src>>x;
        w[src] += x;
    }

    dfs(1);
    for(int i=1;i<=N;i++) cout<<w[i]<<' ';
}