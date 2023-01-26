/* BOJ 6416 트리인가? - 2023.01.11 */
#include <bits/stdc++.h>
using namespace std;

int indegree[15];

bool isTree() {
    int zero = 0, one = 0, other = 0;
    for(int i=0;i<15;i++) {
        if(indegree[i] == -1) continue;

        if(indegree[i] == 0) zero++;
        else if(indegree[i] == 1) one++;
        else other++;
    }

    return (other == 0 && zero == 1) || (other == 0 && zero == 0 && one == 0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int TC = 0;
    while(1) {
        TC++;
        for(int i=0;i<15;i++) indegree[i] = -1;

        while(1) {
            int u, v; cin>>u>>v;
            if(u == 0 && v == 0) break;
            if(u == -1 && v == -1) return 0;
            if(indegree[u] == -1) indegree[u] = 0;

            if(indegree[v] == -1) indegree[v] = 1;
            else indegree[v] += 1;
        }

        //결과 출력
        if(isTree()) cout<<"Case "<<TC<<" is a tree.\n";
        else cout<<"Case "<<TC<<" is not a tree.\n";
    }
    return 0;
}