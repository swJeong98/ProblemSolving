/* BOJ 16987 계란으로 계란치기 - 2022.07.26 */
#include <bits/stdc++.h>
#define X first //내구도
#define Y second //무게
using namespace std;

int N, ans;
pair<int,int> A[10];

void dfs(int idx, int cnt){
    if(idx == N){
        ans = max(ans, cnt);
        return;
    }

    bool empty = true;
    for(int i=0;i<N;i++){
        if(i == idx) continue;
        if(A[i].X > 0) empty = false;
    }

    if(A[idx].X <= 0) dfs(idx+1, cnt);
    else if(empty){
        dfs(idx+1, cnt);
    }
    else{
        for(int i=0;i<N;i++){
            if(A[i].X <= 0) continue;
            if(i == idx) continue;
            A[i].X -= A[idx].Y;
            A[idx].X -= A[i].Y;
            int brk = 0;
            if(A[i].X <= 0) brk += 1;
            if(A[idx].X <= 0) brk += 1;
            dfs(idx+1, cnt+brk);
            A[i].X += A[idx].Y;
            A[idx].X += A[i].Y;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].X>>A[i].Y;

    dfs(0, 0);
    cout<<ans;
    return 0;
}