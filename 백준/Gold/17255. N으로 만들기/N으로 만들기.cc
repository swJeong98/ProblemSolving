/* BOJ 17255 N으로 만들기 - 2023.10.04*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans;

void dfs(string str) {
    if(str.size() == 1) {
        ans += 1;
        return;
    }

    set<string> s;
    int len = str.size();

    string front = str.substr(1, len);
    string back = str.substr(0, len-1);

    if(s.find(front) == s.end()) {
        s.insert(front);
        dfs(front);
    }

    if(s.find(back) == s.end()) {
        s.insert(back);
        dfs(back);
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin>>N;
    string str = to_string(N);

    dfs(str);

    cout << ans;

    return 0;   
}
