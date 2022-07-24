/*BOJ 1463번 1로 만들기 - 2022.02.04*/
#include <iostream>
using namespace std;

int D[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    D[1] = 0;
    for(int i=2;i<=N;i++){
        int a = (i%3==0) ? D[i/3] + 1 : 10000000;
        int b = (i%2==0) ? D[i/2] + 1 : 10000000;
        int c = D[i-1] + 1;
        int tmp = min(a,b);
        D[i] = min(tmp,c);
    }
    cout<<D[N];
} 