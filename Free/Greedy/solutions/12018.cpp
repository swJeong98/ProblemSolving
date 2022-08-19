/* BOJ 12018 Yensei TOTO - 2022.08.19 */
#include <bits/stdc++.h>
using namespace std;

int limit[105];
vector<int> registered[105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;
    for(int i=0;i<N;i++){
        int P, L; cin>>P>>L;
        limit[i] = L;
        for(int j=0;j<P;j++){
            int x; cin>>x;
            registered[i].push_back(x);
        }
    }

    for(int i=0;i<N;i++) sort(registered[i].begin(), registered[i].end(), greater<int>());

    vector<int> needed;
    for(int i=0;i<N;i++){
        if(registered[i].size() < limit[i]) needed.push_back(1);
        else needed.push_back(registered[i][limit[i]-1]);
    }
    sort(needed.begin(), needed.end());
    int ans = 0;
    for(int i=0;i<needed.size();i++){
        if(M < needed[i]) break;
        ans += 1;
        M -= needed[i];
    }
    cout<<ans;
    return 0;
}