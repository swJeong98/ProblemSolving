/**
 * BOJ 17073 나무 위의 빗물 - 2023.01.27
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, W, leaf; //노드의 수, 1번 노드(루트)에 고인 물, 리프 노드 개수
vector<int> adj[500005]; //인접 리스트

int main()
{
//    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin>>N>>W;
    for(int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //트리의 리프 노드는, 반드시 부모 노드만 연결되어 인접 리스트 크기가 1
    for(int i=2; i<=N; i++) {
        if(adj[i].size() == 1) leaf += 1;
    }

    //정답은 W/리프 노드의 개수
    double ans = (double)W / (double)leaf;

    //실수 오차 10^(-3) 까지 허용
    printf("%.8lf\n", ans);

    return 0;
}