/*BOJ 1260 DFS와 BFS- 2022.03.14*/
#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int graph[1005][1005];
bool isVisit[1005];

void DFS(int st){
    isVisit[st] = true;
    stack<int> stk; stk.push(st);
    cout<<st<<' ';
    while(!stk.empty()){
        int cur = stk.top();
        bool isChange = false;
        for(int i=1;i<=N;i++){
            if(isVisit[i]) continue;
            if(graph[cur][i] == 0) continue;
            stk.push(i); isVisit[i] = true; 
            cout<<i<<' '; isChange = true; break;
        }
        if(!isChange) stk.pop();
    }
}

void BFS(int st){
    fill(isVisit+1,isVisit+N+1,false);
    isVisit[st] = true;
    queue<int> Q; Q.push(st);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout<<cur<<' ';
        for(int i=1;i<=N;i++){
            if(isVisit[i]) continue;
            if(graph[cur][i] == 0) continue;
            Q.push(i); isVisit[i] = true; 
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        int a, b; cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    DFS(V); cout<<'\n';
    BFS(V);
    return 0;
}