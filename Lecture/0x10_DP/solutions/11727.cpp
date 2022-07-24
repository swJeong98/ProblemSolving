/*BOJ 11727번 2xn 타일링 2 - 2022.02.08*/
#include <iostream>
using namespace std;

int D[1001]; //2*i 직사각형을 채우는 방법의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    D[1] = 1;
    D[2] = 3;
    for(int i=3;i<=N;i++){
        D[i] = (D[i-1] + (2*D[i-2])) % 10007;
    }
    cout<<D[N];
} 