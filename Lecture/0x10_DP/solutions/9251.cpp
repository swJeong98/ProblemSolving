/**
 * BOJ 9251 LCS - 2023.01.23
 */
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s1, s2; cin>>s1>>s2;
    s1.insert(s1.begin(), ' ');
    s2.insert(s2.begin(), ' ');

    for(int i=1; i<s1.size(); i++) {
        for(int j=1; j<s2.size(); j++) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    cout<<dp[s1.size()-1][s2.size()-1];
    return 0;
}