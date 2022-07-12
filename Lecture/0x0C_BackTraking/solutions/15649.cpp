/*BOJ 15649번 N과 M(1) - 2022.01.17*/
#include <iostream>
using namespace std;

int N,M;
int arr[8];
bool isUsed[9];

void func(int K);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    func(0);
}

void func(int K){
    if(K==M){ //base condition
        for(int i=0;i<M;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
     
    for(int i=1;i<=N;i++){
        if(!isUsed[i]){
            arr[K] = i;
            isUsed[i] = true;
            func(K+1);
            isUsed[i] = false;
        }
    }
}