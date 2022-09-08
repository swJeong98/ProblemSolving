/* BOJ 1915 가장 큰 정사각형 - 2022.09.08 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int pref[1005][1005], board[1005][1005], dp[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string s; cin>>s;
        for(int j=1;j<=M;j++){
            board[i][j] = s[j-1] - '0';
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + board[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j] == 0) {dp[i][j] = 0; continue;}
            if(dp[i-1][j-1] == 0) {dp[i][j] = 1; continue;}
            int val = dp[i-1][j-1] + 1;
            int tmp = pref[i][j] - pref[i][j-val] - pref[i-val][j] + pref[i-val][j-val];
            if(val*val == tmp) dp[i][j] = val;
            else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        }
    }

    int mx = -1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            mx = max(mx, dp[i][j]);
        }
    }

    cout<<mx*mx;
    return 0;
}