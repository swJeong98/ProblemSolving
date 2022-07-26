/* BOJ 2110 공유기 설치 - 2022.05.23 */
#include <bits/stdc++.h>
using namespace std;

int A[200005];
int N, C;

bool check(int x){
	int cnt = 0, cur = A[0];
    for(int i=0;i<N;i++){
        if(i==0) {
            cnt = 1;
            continue;
        }
        if(A[i] - cur >= x){
            cur = A[i];
            cnt++;
        }
    }
	return cnt >= C;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>C;
	for(int i=0;i<N;i++) cin>>A[i];
	sort(A,A+N);

	int mx = A[N-1] - A[0];
	int lo = 1, hi = mx + 1;
	while(lo + 1 < hi){
		int mid = (lo+hi)/2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout<<lo<<'\n';
	return 0;
}