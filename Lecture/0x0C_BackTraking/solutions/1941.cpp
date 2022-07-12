/*BOJ 1941번 소문난 칠공주 - 2022.01.21*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char Seat[5][5];
bool mask[25];
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // do{
    //     bool visit[5][5];
    //     cout<<boolalpha<<visit[1][1];
    // }while(1); 
    /*Input*/
    for(int i=0;i<5;i++){
        string s; cin>>s;
        for(size_t j=0;j<s.size();j++){
            Seat[i][j] = s[j];
        }
    }
    
    fill(mask+7,mask+25,true);
    do{
        queue<pair<int,int>> Q;
        bool isGroup[5][5]={};
        bool visit[5][5]={};
        int adjacent = 0;
        int Scnt = 0;
        for(int i=0;i<25;i++){
            if(!mask[i]){
                int x=i/5; int y=i%5;
                isGroup[x][y] = true;
                if(Q.empty()){
                    Q.push({x,y});
                    visit[x][y] = true;
                }
            }
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            adjacent++;
            if(Seat[cur.first][cur.second]=='S') Scnt++;
            for(int dir=0;dir<4;dir++){
                int nr = cur.first + dr[dir];
                int nc = cur.second + dc[dir];
                if(nr<0 || nr>=5 ||nc<0 ||nc>=5 ||visit[nr][nc]|| !isGroup[nr][nc]) continue;
                Q.push({nr,nc});
                visit[nr][nc]=true;
            }
        }
        if(adjacent==7 && Scnt>=4) ans++;
    } while(next_permutation(mask,mask+25));
    cout<<ans;
}