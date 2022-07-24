/*BOJ 11726번 2xN 타일링 - 2022.02.04*/
#include <iostream>
using namespace std;

int D[1001];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    D[1] = 1;
    D[2] = 2;
    for(int i=3;i<=N;i++){
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }
    cout<<D[N];
} 