/*BOJ 11047번 동전0 - 2022.02.10*/
#include <iostream>
#include <algorithm>
using namespace std;

int c[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>c[i];
    sort(c,c+N,greater<int>());
    int cur = 0;
    int ans = 0;
    while(K != 0){
        ans += K/c[cur];
        K %= c[cur];
        cur++;
    }
    cout<<ans;
}