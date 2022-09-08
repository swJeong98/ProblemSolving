/* BOJ 2011 암호코드 - 2022.09.07 */
#include <bits/stdc++.h>
using namespace std;

int dp[5005];
const int MOD = (int)1e6;

bool isValid(char a, char b){
    if(a > '2' || a == '0') return false;
    if(a == '2' && b >= '7') return false;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin>>s;
    int N = (int)s.size();
    if(N == 1) {
        if(s[0] == '0') cout<<0;
        else cout<<1;
        return 0;
    }

    dp[1] = (s[0] == '0') ? -1 : 1;
    if(dp[1] == -1) dp[2] = -1;
    else {
        if(s[1] == '0'){
            if(s[0] == '1' || s[0] == '2') dp[2] = 1;
            else dp[2] = -1;
        }
        else dp[2] = (isValid(s[0], s[1])) ? 2 : 1;
    }

    for(int i=3;i<=N;i++){
        bool chk1 = false, chk2 = false;
        if(s[i-1] != '0' && dp[i-1] != -1) {dp[i] += dp[i-1]; chk1 = true;}
        if(isValid(s[i-2], s[i-1]) && dp[i-2] != -1) {dp[i] += dp[i-2]; chk2 = true;}

        if(!chk1 && !chk2) dp[i] = -1;
        else dp[i] %= MOD;
    }
    if(dp[N] == -1) cout<<0;
    else cout<<dp[N];
    return 0;
}