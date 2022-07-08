/*BOJ 1926 그림- 2022.03.15*/
#include <bits/stdc++.h>
using namespace std;

int picture[505][505];
int dist[505][505];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N,M; 

int BFS(int i, int j){
    int component = 1;
    dist[i][j] = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<1 || nx>N ||ny<1 ||ny>M ) continue;
            if(picture[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            component++;
        }
    }
    return component;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    int cnt = 0;
    int mx = 0;
    for(int i=0;i<N+2;i++) fill(dist[i],dist[i]+M+2,-1);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>picture[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(picture[i][j] == 0) continue;
            if(dist[i][j] >= 0) continue;
            cnt++;
            mx = max(mx,BFS(i,j));
        }
    }
    cout<<cnt<<'\n'<<mx;
    return 0;
}