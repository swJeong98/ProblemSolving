#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, K;
int board[15][15];
vector<pair<int,int>> p; //참가자들의 위치들
pair<int,int> e; //탈출 지점

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

bool escape[15];

int ans = 0; //이동거리의 합

bool isIN(const pair<int,int>& LT, const pair<int,int>& target, int len) {
    return target.X >= LT.X && target.X <= LT.X + len-1 && target.Y >= LT.Y && target.Y <= LT.Y + len-1;
}

int calc(const pair<int,int>& p1, const pair<int,int>& p2) {
    return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
}

//참가자와 출구를 포함한 정사각형 중 r,c가 작은 좌상단 찾기
pair<int,int> findRec(const pair<int,int>& p1, const pair<int,int>& p2, int len) {
    for(int i=1; i<=N-len+1; i++) {
        for(int j=1; j<=N-len+1; j++) {
            if(isIN({i, j}, p1, len) && isIN({i, j}, p2, len)) {
                return {i, j};
            }
        }
    }
}

//좌상단(LeftTop)기준 정사각형 "회전"
void rotate(const pair<int,int>& LT, int len) {
    int tmp[15][15];
    bool flag[15] = {};
    pair<int,int> tmpExit;
    bool mark = false;

    for(int i=LT.X; i<=LT.X+len-1; i++) {
        for(int j=LT.Y; j<=LT.Y+len-1; j++) {
            if(board[i][j] > 0) board[i][j] -= 1;
            else if(!mark && i == e.X && j == e.Y){
                tmpExit = {LT.X+(j-LT.Y), (LT.Y+len-1)-(i-LT.X)};
                mark = true;
            }else{
                for(int k=0; k<p.size(); k++) {
                    if(escape[k]) continue;
                    if(flag[k]) continue;
                    if(i != p[k].X || j != p[k].Y) continue;
                    flag[k] = true;
                    p[k] = {LT.X+(j-LT.Y), (LT.Y+len-1)-(i-LT.X)};
                }
            }
            tmp[LT.X+(j-LT.Y)][(LT.Y+len-1)-(i-LT.X)] = board[i][j];
        }
    }
    e = tmpExit;

    for(int i=LT.X; i<=LT.X+len-1; i++) {
        for(int j=LT.Y; j<=LT.Y+len-1; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

bool finish() {
    for(int i=0; i<M; i++) {
        if(!escape[i]) return false;
    }
    return true;
}

int main() {
    
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>K;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>board[i][j];
        }
    }

    for(int i=0; i<M; i++) {
        int x, y; cin>>x>>y;
        p.push_back({x, y});
    }

    int x, y; cin>>x>>y;
    e = {x, y};

    for(int tc=0; tc<K; tc++) {

        //이동
        for(int i=0; i<p.size(); i++) {
            if(escape[i]) continue;
            auto cur = p[i];
            for(int dir=0; dir<4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if(board[nx][ny] != 0) continue;
                if(calc(cur, e) <= calc({nx, ny}, e)) continue;
                ans += 1;
                p[i] = {nx, ny};
                if(nx == e.X && ny == e.Y) escape[i] = true;
                break;
            }
        }

        if(finish()) {
            cout << ans << '\n';
            cout << e.X << ' ' <<e.Y;
            return 0;
        }

        //가장 작은 정사각형 좌상단, 우하단 찾기
        int mn = 15; //정사각형 최소 길이
        pair<int,int> tmp = {15,15};
        for(int i=0; i<p.size(); i++) {
            if(escape[i]) continue;

            int len = max(abs(p[i].X - e.X), abs(p[i].Y - e.Y)) + 1;
            if(mn < len) continue;

            if(mn == len) {
                tmp = min(tmp, findRec(p[i], e, len));
            }else{
                tmp = findRec(p[i], e, len);
                mn = len;
            }
        }

        //회전
        rotate(tmp, mn);
    }
    cout << ans << '\n';
    cout << e.X << ' ' <<e.Y;
    return 0;
}
