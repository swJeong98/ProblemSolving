/*BOJ 11659번 구간 합 구하기 4 - 2022.02.04*/
#include <iostream>
using namespace std;

int arr[100001];
int S[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>arr[i];
    S[1] = arr[1];
    for(int i=2;i<=N;i++) S[i] = S[i-1] + arr[i];
    for(int i=0;i<M;i++){
        int l,r;
        cin>>l>>r;
        cout<<S[r]-S[l-1]<<'\n';
    }
} 