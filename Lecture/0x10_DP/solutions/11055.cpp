/* BOJ 11055 가장 큰 증가하는 부분 수열 - 2022.05.11 */
#include <bits/stdc++.h>
using namespace std;

int A[1005], dp[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    for(int i=1;i<=N;i++) dp[i] = A[i];

    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(A[j] < A[i] && dp[j] + A[i] > dp[i]){
                dp[i] = dp[j] + A[i];
            }
        }
    }
    cout<<*max_element(dp+1, dp+N+1);
}