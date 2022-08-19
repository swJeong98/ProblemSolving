/* BOJ 1461 도서관 - 2022.08.19 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin>>N>>M;

    vector<int> p, n;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        if(x < 0) n.push_back(x);
        else p.push_back(x);
    }

    sort(p.begin(), p.end());
    sort(n.begin(), n.end());

    int pSize = (int)p.size(), nSize = (int)n.size();
    int ans = 0;
    for(int i=pSize-1;i>=0;i-=M) ans += 2 * p[i];
    for(int i=0;i<nSize;i+=M) ans += 2 * abs(n[i]);

    int val1 = -1e5, val2 = -1e5;
    if(!p.empty()) val1 = p[pSize-1];
    if(!n.empty()) val2 = abs(n[0]);
    ans -= max(val1, val2);
    cout<<ans;

    return 0;
}
