/*BOJ 2193번 이친수 - 2022.02.08*/
#include <iostream>
using namespace std;

long long D[91][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    D[1][0] = 0, D[1][1] = 1;
    for(int i=2;i<=N;i++){
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }
    cout<<D[N][0]+D[N][1];
} 