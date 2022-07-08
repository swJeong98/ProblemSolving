/*BOJ 2573 빙산 - 2022.03.22*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> Ice;
int N,M; 
int Land[305][305];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool isConnect(){
    bool Visit[305][305] = {};
    int CC = 0; //connected component
    for(auto i=0; i<Ice.size(); i++){
        auto cur = Ice[i];
        if(Land[cur.X][cur.Y] == 0 || Visit[cur.X][cur.Y]) continue;
        CC++; Visit[cur.X][cur.Y] = true;
        queue<pair<int,int>> q;
        q.push({cur.X,cur.Y});
        while(!q.empty()){
            auto now = q.front(); q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = now.X + dx[dir];
                int ny = now.Y + dy[dir];
                if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
                if(Land[nx][ny] == 0 || Visit[nx][ny]) continue;
                Visit[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(CC ==0){
        cout<<0;
        exit(0);
    }
    if(CC==1) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>Land[i][j];
            if(Land[i][j] != 0) Ice.push_back({i,j});
        }
    }
    
    int iter = 0;
    while(1){
        if(!isConnect()) break;
        iter++;
        vector<int> adjacent;
        for(auto i=0; i<Ice.size(); i++){
            auto cur = Ice[i];
            int tmp = 0;
            if(Land[cur.X][cur.Y] == 0) {
                adjacent.push_back(tmp);
                continue;
            }
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<1 ||nx>N ||ny<1 ||ny>M) continue;
                if(Land[nx][ny] == 0) tmp++;
            }
            adjacent.push_back(tmp);
        }
        for(auto i=0; i<Ice.size(); i++){
            auto cur = Ice[i];
            Land[cur.X][cur.Y] = max(0,Land[cur.X][cur.Y]-adjacent[i]);
        }
    }
    cout<<iter;
    return 0;
}