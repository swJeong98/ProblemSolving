/* BOJ 2805 나무 자르기- 2022.05.16 */
#include <bits/stdc++.h>
using namespace std;

long long N,M; 
long long H[1000005];

bool check(long long x){
    long long cnt = 0;
    for(int i=0;i<N;i++){
        if(x >= H[i]) continue;
        cnt += (H[i]-x);
    }
    return cnt >= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    
    cin>>N>>M;
    long long mx = -1;
    for(int i=0;i<N;i++) {
        cin>>H[i];
        mx = max(mx, H[i]);
    }

    long long lo = 0, hi = mx;
    while(lo + 1 < hi){
        long long mid = (lo + hi)/2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo<<'\n';
	return 0;
}