/*BOJ 15650번 N과 M(3) - 2022.01.17*/
#include <iostream>
using namespace std;

int N,M;
void func(int num);
int arr[7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    func(0);
}

void func(int num){
    if(num==M){
        for(int i=0;i<M;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        arr[num] = i;
        func(num+1);
    }
}