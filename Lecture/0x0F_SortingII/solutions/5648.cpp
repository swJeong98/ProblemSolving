/*BOJ 5648번 역원소 정렬 - 2022.01.26*/
#include <iostream>
#include <algorithm>
using namespace std;

long long temp[1000000];
long long arr[1000000];
void getReverse(long long n,int idx);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>temp[i];
    for(int i=0;i<N;i++) getReverse(temp[i],i);
    sort(arr,arr+N);
    for(int i=0;i<N;i++) cout<<arr[i]<<'\n';
}

void getReverse(long long n,int idx){
    char tmp[12]={};
    int cur=0;
    while(n){
        tmp[cur++] = (n % 10)+48;
        n /= 10;
    }
    arr[idx] = atoll(tmp);
}