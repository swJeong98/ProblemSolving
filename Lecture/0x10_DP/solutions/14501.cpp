/* BOJ 14501 퇴사  - 2022.07.27 */
#include <bits/stdc++.h>
#define X first //걸리는 기간
#define Y second //상담 금액
using namespace std;

int N, ans;
pair<int,int> A[20];

void dfs(int idx, int x){
    if(idx > N) {
        ans = max(ans, x);
        return;
    }

    if(idx-1+A[idx].X <= N){
        dfs(idx+A[idx].X, x+A[idx].Y);
        dfs(idx+1, x);
    }
    else{
        dfs(idx+1, x);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i].X>>A[i].Y;

    dfs(1,0);
    cout<<ans;
    return 0;
}