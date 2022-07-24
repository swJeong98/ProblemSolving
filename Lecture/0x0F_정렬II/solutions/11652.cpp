/*BOJ 11652번 카드 - 2022.01.26*/
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr,arr+N);
    int mx=0;
    ll cur=arr[0];
    int cnt=1;
    ll ans = arr[0];
    for(int i=1;i<N;i++){
        if(cur != arr[i]){
            cur = arr[i];
            if(mx<cnt) {
                mx = cnt;
                ans = arr[i-1];
            }
            cnt=1;
        }
        else cnt++;
    }
    if(mx<cnt) ans = arr[N-1];
    cout<<ans;
}