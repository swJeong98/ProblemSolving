/* BOJ 22856 트리 순회 - 2022.08.15 */
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int left, right, parent;
};

Node node_pool[100005];
int root = 1;
int order = 1;
int fin, cnt;
int N;
bool valid = true;

void inorder(int cur){
    if(node_pool[cur].left != -1)  inorder(node_pool[cur].left);
    if(order == N) fin = cur;
    order++;
    if(node_pool[cur].right != -1) inorder(node_pool[cur].right);
}

void similar_inorder(int cur){
    if(node_pool[cur].left != -1 && valid) {
        cnt += 1;
        similar_inorder(node_pool[cur].left);
    }
    if(node_pool[cur].right != -1 && valid){
        cnt += 1;
        similar_inorder(node_pool[cur].right);
    }
    if(cur == fin) {valid = false; return;}
    if(valid) cnt += 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    node_pool[root].parent = -1;
    for(int i=1;i<=N;i++){
        int x, a, b; cin>>x>>a>>b;
        node_pool[x].left = a;
        node_pool[x].right = b;
        node_pool[a].parent = x;
        node_pool[b].parent = x;
    }
    inorder(root);
    similar_inorder(root);
    cout<<cnt;
    return 0;
}
