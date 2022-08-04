/* BOJ 2003 수들의 합 2 - 2022.08.05 */
#include <bits/stdc++.h>
using namespace std;

int A[10005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	int N, M; cin>>N>>M;
	for(int i=0;i<N;i++) cin>>A[i];

	int l = 0, r = 0;
	int sum = A[0];
	int ans = 0;
	while(r <= N-1){
		if(sum < M){
			r += 1;
			if(r == N) break;
			sum += A[r];
		}
		else if(sum == M){
			ans += 1;
			sum -= A[l++];
		}
		else{
			sum -= A[l++];
		}
	}
	cout<<ans;
    return 0;
}