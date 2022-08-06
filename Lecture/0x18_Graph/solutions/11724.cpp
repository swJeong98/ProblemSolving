/*BOJ 11724 연결요소의 개수 - 2022.01.16*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];
bool visit[1001];
int N,M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=1;i<=N;i++) v[i].push_back(i);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<v[i].size();j++){
            queue<int> Q;
            if(!visit[v[i][j]]) {
                visit[v[i][j]] = true;
                Q.push(v[i][j]);
                ans++;
            }
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                for(int i=0;i<v[cur].size();i++){
                    if(!visit[v[cur][i]]){
                        visit[v[cur][i]] = true;
                        Q.push(v[cur][i]);
                    }
                }
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     if(!visit[i]) ans++;
    // }
    cout<<ans;
}