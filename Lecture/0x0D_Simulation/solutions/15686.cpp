/*BOJ 15686번 치킨 배달 - 2022.01.25*/
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

/*variable*/
vector<pair<int,int>> chicken; //전체 치킨 집 좌표를 저장하는 벡터
vector<pair<int,int>> home;    //전체 집 좌표를 저장하는 벡터
pair<int,int> list[13];        //선택된 M개의 치킨 집 좌표를 저장하는 벡터
int city[51][51];
int N,M;
int ans = 2147483647;
/*prototype*/
void func(int k,int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>city[i][j];
            if(city[i][j]==1) home.push_back({i,j});
            if(city[i][j]==2) chicken.push_back({i,j});
        }
    }
    func(0,0);
    cout<<ans;
}

void func(int k,int start){
    if(k==M){
        int res = 0;
        for(int i=0;i<home.size();i++){
            int tmp = 2147483647;
            int curX = home[i].X;
            int curY = home[i].Y;
            for(int j=0;j<M;j++) tmp = min(tmp,abs(curX-list[j].X)+abs(curY-list[j].Y));
            res += tmp;
        }
        ans = min(ans,res);
        return;
    }
    for(int i=start;i<chicken.size();i++){
        list[k].X = chicken[i].X;
        list[k].Y = chicken[i].Y;
        func(k+1,i+1);
    }
}