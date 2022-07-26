/* BOJ 1253 좋다 - 2022.04.28 */
#include <bits/stdc++.h>
using namespace std;

long long A[2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A,A+N);
    
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            long long target = A[i] - A[j];
            auto st = lower_bound(A,A+N,target)-A;
            auto en = upper_bound(A,A+N,target)-A;
            if(st==en) continue;
            if(en-st == 1){
                if(st==i || st==j) continue;
                ans++; break;
            }
            else if(en-st == 2){
                if(st==i || st==j ||en-1 == i || en-1 == j) continue;
                ans++; break;
            }
            else {ans++; break;}
        }
    }
    cout<<ans;
}