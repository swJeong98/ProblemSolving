/* BOJ 1654 랜선 자르기 - 2022.05.16 */
#include <bits/stdc++.h>
using namespace std;

long long K,N;
long long A[10005];

bool check(long long x){
    long long cnt = 0;
    for(int i=0;i<K;i++) cnt += A[i]/x;
    return cnt >= N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin>>K>>N;
    for(int i=0;i<K;i++) cin>>A[i];

    long long lo = 1, hi = 0x7fffffff + (long long)1;
    while(lo + 1 < hi){
        long long mid = (lo + hi)/2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo;
}