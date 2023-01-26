/**
 * BOJ 14675 단절점과 단절선 - 2023.01.25
 */
#include <bits/stdc++.h>
using namespace std;

int N, Q;
pair<int,int> edge[100005];
vector<int> adj[100005];


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;

    for(int i=0; i<N-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[i+1] = {a, b};
    }

    cin>>Q;
    for(int i=0; i<Q; i++) {
        int t, k; cin>>t>>k;
        if(t == 1) { //k번 정점이 단절점
            if(adj[k].size() >= 2) cout<<"yes\n";
            else cout<<"no\n";
        }else{ //k번째 간선이 단절선
            cout<<"yes\n";
        }
    }
    return 0;
}