/*BOJ 1149번 RGB거리 - 2022.02.04*/
#include <iostream>
using namespace std;

int D[1001][3]; //D[i][0] : 빨강, D[i][1] : 초록, D[i][2] : 파랑
int R[1001]; 
int G[1001]; 
int B[1001];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>R[i]>>G[i]>>B[i];

    D[1][0] = R[1];
    D[1][1] = G[1];
    D[1][2] = B[1];
    for(int i=2;i<=N;i++){
        D[i][0] = min(D[i-1][1],D[i-1][2]) + R[i];
        D[i][1] = min(D[i-1][0],D[i-1][2]) + G[i];
        D[i][2] = min(D[i-1][0],D[i-1][1]) + B[i];
    }
    cout<<min(D[N][0],min(D[N][1],D[N][2]));
} 