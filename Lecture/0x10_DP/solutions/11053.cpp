/* BOJ 11053 가장 긴 증가하는 부분 수열 - 2022.07.09 */
#include <bits/stdc++.h>
using namespace std;

int A[1005];
int L[1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];

    int last = 1;
    for(int i=1;i<=N;i++){
        if(last == 1 || L[last-1] < A[i]){
            L[last++] = A[i];
            continue;
        }

        if(L[last-1] >= A[i]){
            auto pos = lower_bound(L+1, L+last ,A[i]) - L;
            L[pos] = A[i];
            continue;
        }
    }
    cout<<last-1; 
}