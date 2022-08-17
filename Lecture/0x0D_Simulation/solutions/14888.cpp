/* BOJ 14888 연산자 끼워넣기 - 2022.08.17 */
#include <bits/stdc++.h>
using namespace std;

int N;
int A[11], op[4];
int mx = - (1e9 + 5), mn = 1e9 + 5;

void solve(int val, int idx){
    if(idx == N){
        mx = max(mx, val);
        mn = min(mn, val);
        return;
    }

    for(int i=0;i<4;i++){
        if(op[i] == 0) continue;
        op[i]--;
        if(i == 0) solve(val+A[idx], idx+1);
        else if(i == 1) solve(val - A[idx], idx+1);
        else if(i == 2) solve(val * A[idx], idx+1);
        else solve(val / A[idx], idx+1);
        op[i]++;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<4;i++) cin>>op[i];

    solve(A[0], 1);
    cout<<mx<<'\n'<<mn;
    return 0;
}
