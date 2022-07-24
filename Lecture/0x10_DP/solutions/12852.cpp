/*BOJ 12852번 1로 만들기 2 - 2022.02.05*/
#include <iostream>
using namespace std;

int D[1000001];
int pre[1000001];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    D[1] = 0;
    D[2] = 1;
    D[3] = 1;
    pre[2] = 1;
    pre[3] = 1;
    for(int i=4;i<=N;i++){
        D[i] = D[i-1] + 1;
        pre[i] = i-1;
        if(i%3==0 && D[i] > D[i/3]+1){
            D[i] = D[i/3] + 1;
            pre[i] = i/3;
        }
        if(i%2==0 && D[i] > D[i/2]+1){
            D[i] = D[i/2] + 1;
            pre[i] = i/2;
        }
    }
    cout<<D[N]<<'\n';
    int cur = N;
    while(cur != 1){
        cout<<cur<<' ';
        cur = pre[cur];
    }
    cout<<1;
} 