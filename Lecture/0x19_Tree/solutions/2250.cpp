/* BOJ 2250 트리의 높이와 너비 - 2022.08.15 */
#include <bits/stdc++.h>
using namespace std;

int N, root;
int column = 1;

struct Node{
    int left, right, parent;
};

Node node_pool[10005];
int col[10005];
vector<int> depth[10005];

void init(){
    for(int i=1;i<=N;i++) node_pool[i].parent = -1;
}

void dfs(int cur, int d){
    depth[d].push_back(cur);
    for(auto nxt : {node_pool[cur].left, node_pool[cur].right}){
        if(nxt == -1) continue;
        dfs(nxt, d+1);
    }
}

void inorder(int cur){
    if(node_pool[cur].left != -1) inorder(node_pool[cur].left);
    col[cur] = column++;
    if(node_pool[cur].right != -1) inorder(node_pool[cur].right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    init();

    for(int i=1;i<=N;i++){
        int x, l, r; cin>>x>>l>>r;

        node_pool[x].left = l;
        if(l != -1) node_pool[l].parent = x;

        node_pool[x].right = r;
        if(r != -1) node_pool[r].parent = x;
    }
    for(int i=1;i<=N;i++){
        if(node_pool[i].parent == -1) {root = i; break;}
    }

    dfs(root, 1);
    inorder(root);

    int mx = 1;
    int mxDepth = 1;
    for(int i=2;i<=10000;i++){
        if(depth[i].empty()) break;
        if(depth[i].size() == 1) continue;
        int st = depth[i][0], en = depth[i][(int)depth[i].size()-1];

        int tmp = col[en] - col[st] + 1;
        if(mx < tmp) {mx = tmp, mxDepth = i;}
    }
    cout<<mxDepth<<" "<<mx;
    return 0;
}
