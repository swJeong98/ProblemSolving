/*BOJ 1991번 트리 순회 - 2022.02.23*/
#include <iostream>
using namespace std;

class BNode{
public:
    char data;
    char left;
    char right;
};

BNode arr[30];

void PreOrder(char Root){
    if(Root == '.') return;
    cout<<Root;
    PreOrder(arr[Root-'A'].left);
    PreOrder(arr[Root-'A'].right);
}

void Inorder(char Root){
    if(Root == '.') return;
    Inorder(arr[Root-'A'].left);
    cout<<Root;
    Inorder(arr[Root-'A'].right);
}

void PostOrder(char Root){
    if(Root == '.') return;
    PostOrder(arr[Root-'A'].left);
    PostOrder(arr[Root-'A'].right);
    cout<<Root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=0;i<N;i++){
        char ch; cin>>ch;
        arr[ch-'A'].data = ch;
        cin>>arr[ch-'A'].left>>arr[ch-'A'].right;
    }

    PreOrder(arr[0].data); cout<<'\n';
    Inorder(arr[0].data); cout<<'\n';
    PostOrder(arr[0].data);
}