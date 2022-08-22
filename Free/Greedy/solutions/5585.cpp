/* BOJ 5585 거스름돈 - 2022.08.22 */
#include <bits/stdc++.h>
using namespace std;

int coin[6] = {500,100,50,10,5,1};
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int x; cin>>x;
    int cur = 1000 - x;

    int ans = 0;
    for(int i=0;i<6;i++){
        if(cur < coin[i]) continue;
        ans += cur / coin[i];
        cur -= (coin[i]) * (cur / coin[i]);
        if(cur == 0) break;
    }
    cout<<ans;
    return 0;
}
