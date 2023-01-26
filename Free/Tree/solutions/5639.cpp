/*BOJ 5639 이진 검색 트리 - 2023.01.11*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int lc = -1;
    int rc = -1;
};


int idx;
Node pool[1000005];
vector<int> v;

void dfs(int st, int en) {
    if(st >= en) return;

    int i;
    for(i=st+1; i<=en; i++) {
        if(v[st] < v[i]) break;
    }

    //오른쪽 서브 트리가 없는 경우
    if(i > en) {
        pool[v[st]].lc = v[st+1];
        pool[v[st]].rc = -1;

        dfs(st+1, en);
    }
        //왼쪽 서브 트리가 없는 경우
    else if(i == st + 1) {
        pool[v[st]].lc = -1;
        pool[v[st]].rc = v[i];

        dfs(i, en);
    }
    else{
        pool[v[st]].lc = v[st+1];
        pool[v[st]].rc = v[i];

        dfs(st+1, i-1);
        dfs(i, en);
    }
}

void post(int cur) {
    if(cur == -1) return;

    post(pool[cur].lc);
    post(pool[cur].rc);
    cout<<cur<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int x;
    while(cin >> x) {
        v.push_back(x);
    }

    dfs(0, v.size()-1);

    post(v[0]);
    return 0;
}