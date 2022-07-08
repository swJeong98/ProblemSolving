/* BOJ 9466 텀 프로젝트 - 2022.05.06 */
#include <bits/stdc++.h>
using namespace std;

int T,N;
int A[100005];
int state[100005];

const int NOT_VISITED=0;
const int VISITED=1;
const int CYCLE_IN=2;
const int NOT_CYCLE_IN=3;

void dfs(int src){
    int cur = src;
    while(1){
        state[cur] = VISITED;
        cur = A[cur];
        //이미 사이클이거나, 사이클이 아닌 학생으로 결정이 난 경우
        if(state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN){
            cur = src;
            while(state[cur] == VISITED){
                state[cur] = NOT_CYCLE_IN;
                cur = A[cur];
            }
            return;
        }
        //src에서 시작했지만, 다른 학생부터 부분적으로 사이클 생성되는 경우
        if(state[cur] == VISITED && cur != src){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = A[cur];
            }
            cur = src;
            while(state[cur] != CYCLE_IN){
                state[cur] = NOT_CYCLE_IN;
                cur = A[cur];
            }
            return;
        } 
        //src부터 시작된 큰 사이클 하나가 완성
        if(state[cur] == VISITED && cur == src){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = A[cur];
            }
            return;
        }

        if(state[cur] == NOT_VISITED){
            //do notihing;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>T;
    while(T--){
        cin>>N;
        fill(state, state+N+1, 0);
        for(int i=1;i<=N;i++) cin>>A[i];

        for(int i=1;i<=N;i++){
            if(state[i] == NOT_VISITED) dfs(i);
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            if(state[i] == NOT_CYCLE_IN) ans++;
        }
        cout<<ans<<'\n';
    }
}