/* BOJ 2473 세 용액 - 2022.05.13 */
#include <bits/stdc++.h>
using namespace std;

long long A[5005];
int ans[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A, A+N);
    
    long long mn = 3e9 + 5;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            int idx = lower_bound(A, A+N, -(A[i]+A[j])) - A;

            if(idx == N){
                while(idx == N || idx == i || idx == j) idx--;
                if(abs(mn) > abs(A[i]+A[j]+A[idx])){
                    mn = abs(A[i]+A[j]+A[idx]);
                    ans[0] = A[i], ans[1] = A[j], ans[2] = A[idx];
                    continue;
                }
            }
            if(idx != 0 && idx-1 != i && idx-1 != j && abs(mn) > abs(A[i]+A[j]+A[idx-1])){
                mn = abs(A[i]+A[j]+A[idx-1]);
                ans[0] = A[i], ans[1] = A[j], ans[2] = A[idx-1];
            }

            if(idx != i && idx != j && abs(mn) > abs(A[i]+A[j]+A[idx])){
                mn = abs(A[i]+A[j]+A[idx]);
                ans[0] = A[i], ans[1] = A[j], ans[2] = A[idx];
            }

            if(idx != N-1 && idx+1 != i && idx+1 != j && abs(mn) > abs(A[i]+A[j]+A[idx+1])){
                mn = abs(A[i]+A[j]+A[idx+1]);
                ans[0] = A[i], ans[1] = A[j], ans[2] = A[idx+1];
            }
        }
    }
    
    sort(ans,ans+3);
    for(int i=0;i<3;i++) cout<<ans[i]<<' ';
}
