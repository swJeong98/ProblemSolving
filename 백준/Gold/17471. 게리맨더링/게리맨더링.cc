/* BOJ 17471 게리맨더링 - 2023.10.06*/
#include <bits/stdc++.h>
using namespace std;

int N; 
int A[15];
int mark[15];
vector<int> adj[15];

int ans = 1e7;

bool isValid() {
    bool vis[15] = {};

    int cnt = 0;
    
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        cnt += 1;
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]) {
                if(vis[nxt]) continue;
                if(mark[nxt] != mark[cur]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return cnt == 2;
}

void dfs(int idx, int red, int blue) {
    if(idx == N+1) {
        if(red == 0 || blue == 0) return;
        if(!isValid()) return; 

        int sum1 = 0, sum2 = 0;
        for(int i=1; i<=N; i++) {
            if(mark[i] == 1) sum1 += A[i];
            else sum2 += A[i];
        }

        ans = min(ans, abs(sum1-sum2));
        return;
    }

    mark[idx] = 1;
    dfs(idx+1, red+1, blue);
    
    mark[idx] = 2;
    dfs(idx+1, red, blue+1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1; i<=N; i++) cin>>A[i];

    for(int i=1; i<=N; i++) {
        int x; cin>>x;

        for(int j=1; j<=x; j++) {
            int t; cin>>t;
            adj[i].push_back(t);
        }
    }

    dfs(1, 0, 0);

    cout << ((ans == 1e7) ? -1 : ans);

    return 0;   
}
