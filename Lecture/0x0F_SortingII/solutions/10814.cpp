/*BOJ 10814번 나이 정렬하기 - 2022.01.26*/
#include <iostream>
#include <algorithm>
#define pii pair<int,string>
using namespace std;

pii arr[100000];
bool cmp(const pii& a,const pii& b){
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i].first>>arr[i].second;
    stable_sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++) cout<<arr[i].first<<' '<<arr[i].second<<'\n';
}