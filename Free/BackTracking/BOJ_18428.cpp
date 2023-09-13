/* BOJ 18428 감시 피하기 - 2023.09.13*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
int board[10][10];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool flag;

vector<pair<int,int>> v;
vector<pair<int,int>> teacher;

bool OOB(pair<int,int> p) {
    return p.X < 1 || p.X > N || p.Y < 1 || p.Y > N;
}

void check() {
    for(int i=0; i<teacher.size(); i++) {
        
        for(int dir=0; dir<4; dir++) {
            int nx = teacher[i].X + dx[dir];
            int ny = teacher[i].Y + dy[dir];

            while(!OOB({nx, ny})) {
                //'S'
                if(board[nx][ny] == 1) {
                    return;
                }
                //장애물
                if(board[nx][ny] == 3) {
                    break;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    flag = true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            char ch; cin>>ch;
            if(ch == 'S') board[i][j] = 1;
            else if(ch == 'T') {
                board[i][j] = 2;
                teacher.push_back({i, j});
            }
            else { // 'X'
                board[i][j] = 0;
                v.push_back({i, j});    
            }
        }
    }

    for(int i=0; i<v.size(); i++) {
        board[v[i].X][v[i].Y] = 3;
        for(int j=i+1; j<v.size(); j++) {
            board[v[j].X][v[j].Y] = 3;
            for(int k=j+1; k<v.size(); k++) {
                board[v[k].X][v[k].Y] = 3;
                check();
                if(flag) { 
                    cout << "YES";
                    return 0;
                }
                board[v[k].X][v[k].Y] = 0;
            }
            board[v[j].X][v[j].Y] = 0;
        }
        board[v[i].X][v[i].Y] = 0;
    }

    cout << "NO";
    return 0;   
}
