/* BOJ 14002 가장 긴 증가하는 부분 수열 4 - 2022.05.10 */
#include <bits/stdc++.h>
using namespace std;

int A[1005], L[1005], P[1005];

void printPath(int idx, int len){
    if(idx == 0) return;

    if(P[idx] == len){
        printPath(idx-1, len-1);
        cout<<A[idx]<<' ';
    }
    else{
        printPath(idx-1, len);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];

    int last = 1;
    for(int i=1;i<=N;i++){
        if(last == 1 || L[last-1] < A[i]){
            P[i] = last;
            L[last++] = A[i];
            continue;
        }
        if(L[last-1] >= A[i]){
            int pos = lower_bound(L+1,L+last,A[i]) - L;
            L[pos] = A[i];
            P[i] = pos;
        }
    }

    cout<<last-1<<'\n';
    printPath(N, last-1);
}