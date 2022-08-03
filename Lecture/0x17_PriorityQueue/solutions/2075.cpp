/*BOJ 2075번 N번째 큰 수 - 2022.02.25*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[2250005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=0;i<N*N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(N*N),greater<>());
    cout<<arr[N-1];
}