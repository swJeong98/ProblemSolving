/* BOJ 22862 가장 긴 짝수 연속한 부분 수열(large) - 2022.09.01 */
#include <bits/stdc++.h>
using namespace std;

int A[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin>>N>>K;

    bool check = false;
    int l = -1;
    for(int i=0;i<N;i++) {
        cin>>A[i];
        if(A[i] % 2 == 0) check = true;
        if(l == -1 && A[i] % 2 == 0) l = i;
    }

    if(!check) {cout<<0; return 0;}

    int r = l, cnt = 0, ans = 0, tmp = 0;
    while(r < N){
        if(A[r] % 2 == 0) {
            tmp += 1;
            ans = max(ans, tmp);
            r += 1;
        }
        else{
            if(cnt < K) {
                cnt += 1;
                r += 1;
            }
            else{
                l += 1;
                tmp -= 1;
                while(A[l] % 2 == 1) {l += 1; cnt -= 1;}
            }
        }
    }

    cout<<ans;
    return 0;
}
