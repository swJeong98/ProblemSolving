/*BOJ 11728번 배열 합치기 - 2022.01.24*/
#include <iostream>
using namespace std;

int A[1000000];
int B[1000000];
int N,M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];

    int Acur = 0, Bcur = 0;
    while(Acur<=N-1 && Bcur<=M-1){
        if(A[Acur]<B[Bcur]){
            cout<<A[Acur]<<' ';
            Acur++;
        }
        else{
            cout<<B[Bcur]<<' ';
            Bcur++;
        }
    }

    if(Acur<=N-1){
        for(int i=Acur;i<=N-1;i++) cout<<A[i]<<' ';
    }
    else{
        for(int i=Bcur;i<=M-1;i++) cout<<B[i]<<' ';
    }
}