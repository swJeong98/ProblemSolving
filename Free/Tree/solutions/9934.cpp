/* BOJ 9934 완전 이진 트리 - 2022.10.26 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dat[15];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int K; cin>>K;
    int MX = (1<<K) - 1;
    vector<int> v(MX+5);
    for(int i=1;i<=MX;i++) cin>>v[i];

    queue<int> q;
    for(int i=1;i<=MX;i+=2){
        dat[K].push_back(v[i]);
        q.push(i);
    }

    for(int i=K-1;i>=1;i--){
        int sz = (int)q.size();
        if(sz == 1) {dat[1].push_back(v[q.front()]); break;}
        for(int j=0;j<sz/2;j++){
            int v1 = q.front(); q.pop();
            int v2 = q.front(); q.pop();
            int mid = (v1+v2)/2;
            dat[i].push_back(v[mid]);
            q.push(mid);
        }
    }

    for(int i=1;i<=K;i++){
        for(auto& elem : dat[i]){cout<<elem<<' ';}
        cout<<"\n";
    }
    return 0;
}