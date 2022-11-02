/*BOJ 10989번 수 정렬하기 3 - 2022.01.26*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        int a; cin>>a;
        arr[a-1]++;
    }
    for(int i=0;i<10000;i++){
        for(int j=0;j<arr[i];j++){
            cout<<i+1<<'\n';
        }
    }
}