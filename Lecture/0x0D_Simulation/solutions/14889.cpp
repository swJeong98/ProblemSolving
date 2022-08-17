/* BOJ 14889 스타트와 링크 - 2022.08.17 */
#include <bits/stdc++.h>
using namespace std;

int N, total;
int weight[25][25], tmp[10];
int mn = 1e5;

void solve(int idx, int cnt){
    int remain = N - idx, needed = (N/2) - cnt;
    if(remain < needed) return;

    if(cnt == (N/2)){
        int val1 = 0;

        for(int i=0;i<cnt-1;i++){
            for(int j=i+1;j<cnt;j++){
                val1 += weight[tmp[i]][tmp[j]];
                val1 += weight[tmp[j]][tmp[i]];
            }
        }

        bool Valid[25] = {};
        for(int i=0;i<cnt;i++) Valid[tmp[i]] = true;

        vector<int> team;
        for(int i=0;i<N;i++){
            if(!Valid[i]) team.push_back(i);
        }

        int val2 = 0;
        for(int i=0;i<cnt-1;i++){
            for(int j=i+1;j<cnt;j++){
                val2 += weight[team[i]][team[j]];
                val2 += weight[team[j]][team[i]];
            }
        }

        mn = min(mn, abs(val1 - val2));
        return;
    }

    tmp[cnt] = idx;
    solve(idx+1, cnt+1);
    solve(idx+1, cnt);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            cin>>weight[i][j];
        }
    }
    solve(0, 0);
    cout<<mn;
    return 0;
}
