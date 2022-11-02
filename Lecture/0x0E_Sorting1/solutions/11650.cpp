/*BOJ 11650번 좌표 정렬하기 - 2022.01.26*/
#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

pii arr[100000];
bool cmp(pii& a,pii& b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++) cout<<arr[i].first<<' '<<arr[i].second<<'\n';
}