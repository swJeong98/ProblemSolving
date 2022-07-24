/*BOJ 1912번 연속합 - 2022.02.08*/
#include <iostream>
using namespace std;

int A[100000];
int D[100000][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    D[0][0] = D[0][1] = A[0];
    for(int i=1;i<N;i++){
        D[i][0] = max(D[i-1][0],D[i-1][1]);
        D[i][1] = max(D[i-1][1]+A[i],A[i]);
    }
    cout<<max(D[N-1][0],D[N-1][1]);
} 