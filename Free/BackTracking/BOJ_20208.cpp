/* BOJ 20208 진우의 민트초코우유 - 2023.09.13*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, H;
int ans;
pair<int,int> st;
vector<pair<int,int>> milk;

int board[15][15];

int calc(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
}

void traverse() {
    pair<int,int> cur = st;
    int cnt = 0;
    int health = M;
    for(int i=0; i<milk.size(); i++) {
        int nextHealth = health - calc(cur, milk[i]);

        bool canNext = (nextHealth >= 0) ? true : false;
        bool canComeback = (canNext && (nextHealth + H - calc(milk[i], st) >= 0)) ? true : false;

        cnt += 1;

        if(canNext) {
            health -= calc(cur, milk[i]);
            health += H;
            cur = milk[i];
            if(canComeback) {
                ans = max(ans, cnt);
            }
        }else{
            break;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>H;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>board[i][j];
            if(board[i][j] == 2) {
                milk.push_back({i, j});
            }
            if(board[i][j] == 1) {
                st = {i, j};
            }
        }
    }

    sort(milk.begin(), milk.end());
    
    do{
        traverse();
    }while(next_permutation(milk.begin(), milk.end()));

    cout << ans;
    return 0;   
}
