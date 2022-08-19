/* BOJ 2891 카약과 강풍 - 2022.08.19 */
#include <bits/stdc++.h>
using namespace std;

bool broken[15], extra[15];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, S, R; cin>>N>>S>>R;
    for(int i=0;i<S;i++){
        int x; cin>>x;
        broken[x] = true;
    }
    for(int i=0;i<R;i++){
        int x; cin>>x;
        extra[x] = true;
    }

    for(int i=1;i<=N;i++){
        if(broken[i] && extra[i]) {broken[i] = false, extra[i] = false;}
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(!broken[i]) continue;
        if(i > 1 && extra[i-1]) { extra[i-1] = false; continue; }
        if(i < N && extra[i+1]) { extra[i+1] = false; continue; }
        ans += 1;
    }
    cout<<ans;
    return 0;
}
