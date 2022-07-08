/*BOJ 13549 숨바꼭질 3 - 2022.03.19*/
#include <bits/stdc++.h>
using namespace std;

int board1[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N,K; cin>>N>>K;
    fill(board1,board1+200005,-1);

    deque<int> dq;
    dq.push_front(N); board1[N] = 0;
    bool isEscape = false;
    while(!dq.empty() && !isEscape){
        int cur = dq.front(); dq.pop_front();
        for(auto nx : {cur*2,cur-1,cur+1}){
            if(nx<0 || nx>200000) continue;
            if(board1[nx] >= 0) continue;
            //////////////////////////////
            if(nx == cur*2) {
                board1[nx] = board1[cur];
                dq.push_front(nx);
            }
            else {
                board1[nx] = board1[cur]+1;
                dq.push_back(nx);
            }
            if(nx == K) {
                isEscape = true;
                break;
            }
            //////////////////////////////
        }
    }
    cout<<board1[K];
    return 0;
}