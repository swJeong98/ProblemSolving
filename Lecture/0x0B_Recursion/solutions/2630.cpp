/*BOJ 2630번 색종이 만들기 - 2021.01.17*/
#include <iostream>
using namespace std;

void func(int N,int r,int c);
int paper[129][129];
int cnt[2];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>paper[i][j];
        }
    }
    func(N,1,1);
    for(int i=0;i<2;i++) cout<<cnt[i]<<'\n';
}

void func(int N,int r,int c){
    if(N==1){
        cnt[paper[r][c]]++;
        return;
    }

    int first = paper[r][c];
    bool isDiff = false;
    for(int i=r;i<r+N;i++){
        for(int j=c;j<c+N;j++){
            if(paper[i][j]==first) continue;
            isDiff = true;
            break;
        }
    }

    if(!isDiff){
        cnt[first]++;
        return;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int nr = r+(N/2)*i;
            int nc = c+(N/2)*j;
            func(N/2,nr,nc);
        }
    }
}