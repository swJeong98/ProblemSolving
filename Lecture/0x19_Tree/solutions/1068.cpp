/* BOJ 1068 트리 - 2022.08.14 */
#include <bits/stdc++.h>
#define MAX_CHILD 55
using namespace std;

int N, ans;

struct Node{
    struct Node* parent;
    struct Node* child[MAX_CHILD];
};

int node_count, root_num;
Node node_pool[MAX_CHILD];

void init(){
    for(int i=1;i<=N;i++){
        node_pool[i].parent = NULL;
        for(int j=1;j<=N;j++){
            node_pool[i].child[j] = NULL;
        }
    }
}

void del_node(int nd){
    if(nd == root_num) { root_num = -1; return; }
    node_pool[nd].parent->child[nd] = NULL;
}

void dfs(int cur){
    if(cur == -1) return;
    bool isLeaf = true;
    for(int i=1;i<=N;i++){
        if(node_pool[cur].child[i] == NULL) continue;
        isLeaf = false;
        dfs(i);
    }
    if(isLeaf) ans += 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    init();

    for(int i=1;i<=N;i++){
        int x; cin>>x;
        if(x == -1) {root_num = i; continue;}
        x += 1;
        node_pool[i].parent = &node_pool[x];
        node_pool[x].child[i] = &node_pool[i];
    }
    int remove_num; cin>>remove_num;
    del_node(++remove_num);

    dfs(root_num);
    cout<<ans;
    return 0;
}
