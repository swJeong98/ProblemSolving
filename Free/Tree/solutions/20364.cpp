/* BOJ 20364 부동산 다툼 - 2022.09.26 */
#include <bits/stdc++.h>
using namespace std;

int N, Q;
bool vis[(1<<20)+5];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        int x; cin>>x;
        bool check = true;
        int res = 0;
        int originX = x;
        while(x != 1){
            if(vis[x]) {res = x; check = false;}
            x /= 2;
        }
        vis[originX] = true;
        cout<<res<<'\n';
    }
    return 0;
}
