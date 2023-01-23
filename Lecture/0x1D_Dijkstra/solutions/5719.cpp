/**
 * BOJ 5719 거의 최단 경로 - 2023.01.18
 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 5e7;

int N, M; //장소의 수, 도로의 수
int S, D; //시작점, 도착점

int adj[505][505]; //인접 행렬
int radj[505][505]; //역 인접 행렬
int dist[505];

struct cmp {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
        if(p1.Y != p2.Y) return p1.Y > p2.Y;
        return p1.X > p2.X;
    }
};

void clear() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i != j) {
                adj[i][j] = INF;
                radj[i][j] = INF;
            }
        }
    }

    for(int i=1;i<=N;i++) dist[i] = INF;
}

bool Input() {
    cin>>N>>M;
    if(N == 0 && M == 0) return false;
    cin>>S>>D;
    S++; D++;
    clear();
    for(int i=0;i<M;i++) {
        int u, v, w; cin>>u>>v>>w;
        u++; v++;
        adj[u][v] = w;
        radj[v][u] = w;
    }
    return true;
}

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    dist[S] = 0;
    pq.push({S, 0});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.X] != cur.Y) continue;
        for(int i=1;i<=N;i++) {
            if(adj[cur.X][i] == INF) continue;
            if(dist[i] > dist[cur.X] + adj[cur.X][i]) {
                dist[i] = dist[cur.X] + adj[cur.X][i];
                pq.push({i, dist[cur.X] + adj[cur.X][i]});
            }
        }
    }
}

void deleteEdge() {
    queue<int> q;
    q.push(D);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=1; i<=N; i++) {
            if(radj[cur][i] == INF) continue;
            if(dist[i] + adj[i][cur] == dist[cur]) {
                adj[i][cur] = INF;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while(true) {
        //입력 처리 및 새로운 Test Case 위한 리소스 초기화
        if(!Input()) break;

        //다익스트라로 시작점으로 부터 모든 경로까지 최단 거리 계산
        dijkstra();

        //지워야하는 간선 찾기
        deleteEdge();

        //다시 다익스트라 돌리기
        for(int i=1;i<=N;i++) dist[i] = INF;
        dijkstra();

        cout << ( (dist[D] == INF) ? -1 : dist[D] ) <<'\n';
    }
    return 0;
}