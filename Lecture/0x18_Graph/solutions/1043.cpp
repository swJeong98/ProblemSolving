/* BOJ 1043 거짓말 - 2022.08.10 */
#include <bits/stdc++.h>
using namespace std;

int N, M; 
bool adj[55][55], check[55];
vector<int> party[55];
vector<int> known;

void dfs(int cur){
    for(int i=1;i<=N;i++){
        if(!adj[cur][i] || check[i]) continue;
        check[i] = true;
        dfs(i);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int x; cin>>x;
        known.push_back(x);
        check[x] = true;
    }

    for(int i=1;i<=M;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            int x; cin>>x;
            party[i].push_back(x);            
        }
    }

    for(int i=1;i<=M;i++){
        for(int j=0;j<party[i].size();j++){
            for(int k=0;k<party[i].size();k++){
                adj[party[i][j]][party[i][k]] = true;
                adj[party[i][k]][party[i][j]] = true;
            }
        }
    }

    for(auto elem : known) dfs(elem);

    int ans = 0;
    for(int i=1;i<=M;i++){
        ans += 1;
        for(auto elem : party[i]){
            if(!check[elem]) continue;
            ans -= 1;
            break;
        }
    }
    cout<<ans;
    return 0;
}
