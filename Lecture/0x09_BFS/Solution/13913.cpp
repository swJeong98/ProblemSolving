/*BOJ 13913 숨바꼭질 4 - 2022.03.19*/
#include <bits/stdc++.h>
using namespace std;

int board[100005];
int pre[100005];

void printPath(int source,int destination){
    if(source != destination) printPath(source,pre[destination]);
    cout<<destination<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     
    int N,K; cin>>N>>K;
    fill(board,board+100005,-1);

    queue<int> q;
    q.push(N); board[N] = 0;
    
    bool isEscape = false;
    while(!q.empty() && !isEscape){
        int cur = q.front(); q.pop();
        for(auto nxt : {cur*2,cur-1,cur+1}){
            if(nxt<0 || nxt>100000) continue;
            if(board[nxt]>=0) continue;
            board[nxt] = board[cur] + 1;
            q.push({nxt});
            pre[nxt] = cur;
            if(nxt == K) {
                isEscape = true;
                break;
            }
        }
    }

    cout<<board[K]<<'\n';
    printPath(N,K);
    return 0;
}