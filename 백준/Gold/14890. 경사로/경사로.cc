/* BOJ 12851 숨바꼭질 2 - 2022.08.10 */
#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[105][105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>L;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }

    int ans = 0;
    for(int r=1;r<=N;r++){
        vector<bool> check(N+1, false);
        int pre = -1;
        ans += 1;
        for(int c=1;c<=N;c++){
            int cur = board[r][c];
            if(pre == -1 || pre == cur) {pre = cur; continue;}
            if(abs(pre - cur) > 1) {ans -= 1; break;}
            
            if(pre < cur){ // pre + 1 == cur
                if(c - L < 1) {ans -= 1; break;}
                bool ok = true;
                for(int pos = c-L; pos < c; pos++){
                    if(board[r][pos] != pre) {ok = false; break;}
                    if(check[pos]) {ok = false; break;}
                    check[pos] = true;
                }
                if(!ok) {ans -= 1; break;}
                pre = cur;
            }
            else if(pre > cur){ // pre = cur + 1
                if(c+L-1 > N) {ans -= 1; break;}
                bool ok = true;
                for(int pos = c; pos<c+L; pos++){
                    if(board[r][pos] != cur) {ok = false; break;}
                    if(check[pos]) {ok = false; break;}
                    check[pos] = true;
                }
                if(!ok) {ans -= 1; break;}
                pre = cur;
                c += L-1;
            }
        }
    }

    for(int c=1;c<=N;c++){
        vector<bool> check(N+1, false);
        int pre = -1;
        ans += 1;
        for(int r=1;r<=N;r++){
            int cur = board[r][c];
            if(pre == -1 || pre == cur) {pre = cur; continue;}
            if(abs(pre - cur) > 1) {ans -= 1; break;}

            if(pre < cur){
                if(r - L < 1) {ans -= 1; break;}
                bool ok = true;
                for(int pos = r-L; pos<r; pos++){
                    if(board[pos][c] != pre) {ok = false; break;}
                    if(check[pos]) {ok = false; break;}
                    check[pos] = true;
                }
                if(!ok) {ans -= 1; break;}
                pre = cur;
            }
            else if(pre > cur){
                if(r+L-1 > N) {ans -= 1; break;}
                bool ok = true;
                for(int pos = r; pos<r+L; pos++){
                    if(board[pos][c] != cur) {ok = false; break;}
                    if(check[pos]) {ok = false; break;}
                    check[pos] = true;
                }
                if(!ok) {ans -= 1; break;}
                pre = cur;
                r += L-1;
            }
        }
    }
    cout<<ans;
    return 0;   
}