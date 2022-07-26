/* BOJ 15903 카드 합체 놀이 - 2022.07.26 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;
    priority_queue<ll, vector<ll>, greater<ll>> pq; //Min heap

    for(int i=0;i<N;i++){
        ll x; cin>>x;
        pq.push(x);
    }


    while(M--){
        ll mx1 = pq.top();
        pq.pop();
        ll mx2 = pq.top();
        pq.pop();
        ll val = mx1 + mx2;
        pq.push(val);
        pq.push(val);
    }

    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
    return 0;
}