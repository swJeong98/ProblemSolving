/*BOJ 15683번 감시 - 2022.01.24*/
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

char office[9][9]; //입력으로 들어온 사무실 원본 유지
char office2[9][9]; //4^k 개의 case를 test할 배열(k: cctv개수)
vector<pair<int,int>> cctv;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;

bool OOB(int x,int y);
void ResetOffice();
void upd(int x,int y,int dir);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>office[i][j];
            if(office[i][j]>='1' && office[i][j]<='5') cctv.push_back({i,j});
            if(office[i][j]=='0') ans++;
        }
    }
    
    //int Limit = 1 << (2*cctv.size());
    for(int temp=0; temp<(1<<(2*cctv.size())); temp++){
        ResetOffice();
        int brute = temp;
        for(int i=0;i<cctv.size();i++){
            int dir = brute % 4;
            brute /= 4;
            int x,y; tie(x,y) = cctv[i];

            if(office[x][y] == '1'){
                upd(x,y,dir);
            }
            else if(office[x][y]== '2'){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }else if(office[x][y]== '3'){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }else if(office[x][y]== '4'){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }else{ //office[x][y]== '5'
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }
        int t=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(office2[i][j]=='0') t++;
            }
        }
        ans = min(ans,t);
    }
    cout<<ans;
}  

bool OOB(int x,int y){
    return x<1 || x>N || y<1 || y>M;
}

void ResetOffice(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            office2[i][j] = office[i][j];
        }
    }
}

void upd(int x,int y,int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || office2[x][y]=='6') break;
        if(office2[x][y] != '0') continue;
        office2[x][y] = '#';
    }
}