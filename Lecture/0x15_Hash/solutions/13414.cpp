/* BOJ 13414 수강 신청 - 2022.08.08 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

bool cmp(const pair<string,int>& p1, const pair<string,int>& p2){
    return p1.Y < p2.Y;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int K, L; cin>>K>>L;

    unordered_map<string, int> Myhash;

    for(int i=0;i<L;i++){
        string s; cin>>s;
        if(Myhash.find(s) != Myhash.end()) Myhash[s] = i;
        else Myhash.insert({s,i});
    }

    vector<pair<string, int>> ans (Myhash.begin(), Myhash.end());
    sort(ans.begin(), ans.end(), cmp);

    int en = min(K, (int)ans.size());
    for(int i=0;i<en;i++) cout<<ans[i].X<<'\n';
    return 0;
}
