/* BOJ 1620 나는야 포켓몬 마스터 이다솜 - 2022.07.27 */
#include <bits/stdc++.h>
using namespace std;

string A[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    unordered_map<string, int> s;

    int N, M; cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        s[A[i]] = i;
    }    

    while(M--){
        string q; cin>>q;
        if(isdigit(q[0])) cout<<A[stoi(q)]<<'\n';
        else cout<<s[q]<<'\n';
    }
    return 0;
}