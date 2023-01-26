/* BOJ 1991 트리 순회 - 2023.01.11 */
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    int lc = -1, rc = -1;
};

Node pool[30];

void pre(int cur) {
    if(cur == -1) return;

    cout<<(char)('A' + cur);
    pre(pool[cur].lc);
    pre(pool[cur].rc);
}

void in(int cur) {
    if(cur == -1) return;

    in(pool[cur].lc);
    cout<<(char)('A' + cur);
    in(pool[cur].rc);
}

void post(int cur) {
    if(cur == -1) return;

    post(pool[cur].lc);
    post(pool[cur].rc);
    cout<<(char)('A' + cur);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;

    for(int i=0;i<N;i++) {
        char id, lc, rc; cin>>id>>lc>>rc;

        if(lc != '.') pool[id - 'A'].lc = lc - 'A';
        if(rc != '.') pool[id - 'A'].rc = rc - 'A';
    }

    pre(0); cout<<'\n';
    in(0); cout<<'\n';
    post(0); cout<<'\n';
    return 0;
}