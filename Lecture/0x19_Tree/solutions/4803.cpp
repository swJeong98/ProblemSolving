/* BOJ 4803 트리 - 2022.07.07 */
#include <bits/stdc++.h>
using namespace std;

int N, M, cycle;
bool vis[505];
int par[505];
vector<int> adj[505];

void dfs(int cur){
    vis[cur] = true;
    for(int nxt : adj[cur]){
        if(nxt == par[cur]) continue;
        if(vis[nxt]) {cycle = 1; continue;}
        par[nxt] = cur;
        dfs(nxt);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int test_case = 0;
    while(1){
        cin>>N>>M;
        if(N==0 && M==0) break;
        test_case++;
        //Initialization for New Test case
        fill(vis, vis+505, false);
        fill(par, par+505, 0);
        for(int i=0;i<505;i++) adj[i].clear();
        cycle = 0;
        //Input 
        for(int i=0;i<M;i++){
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //Calculate 
        int cnt = 0;
        for(int i=1;i<=N;i++){
            if(vis[i]) continue;
            dfs(i);
            if(cycle != 1) cnt += 1;
            cycle = 0;
        }
        //Output
        if(cnt == 0) cout<<"Case "<<test_case<<": No trees.\n";
        if(cnt == 1) cout<<"Case "<<test_case<<": There is one tree.\n";
        if(cnt > 1) cout<<"Case "<<test_case<<": A forest of "<<cnt<<" trees.\n";
    }
    return 0;
}