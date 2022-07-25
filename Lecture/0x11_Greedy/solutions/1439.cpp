/* BOJ 1439 뒤집기 - 2022.07.26 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin>>s;
    int cnt1 = 0, cnt2 = 0;

    char cur = s[0];
    if(cur == '0') cnt1 += 1;
    else cnt2 += 1;

    for(int i=1;i<s.size();i++){
        if(s[i] == cur) continue;
        else{
            if(cur == '0') cnt2 += 1;
            else cnt1 += 1;
            cur = s[i];
        }
    }
    cout<<min(cnt1, cnt2);
    return 0;
}