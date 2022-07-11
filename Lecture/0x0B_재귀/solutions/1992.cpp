/*BOJ 1992번 쿼드 트리 - 2021.01.17*/
#include <iostream>
using namespace std;

char Data[65][65];
void func(int N,int r,int c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=1;i<=N;i++){
        string s; cin>>s;
        for(size_t j=0;j<s.size();j++){
            Data[i][j+1] = s[j];
        }
    }
    func(N,1,1);
}

void func(int N,int r,int c){
    if(N==1){
        cout<<Data[r][c];
        return;
    }

    bool isDiff = false;
    char first = Data[r][c];
    for(int i=r;i<r+N;i++){
        for(int j=c;j<c+N;j++){
            if(Data[i][j]==first) continue;
            isDiff = true;
            break;
        }
    }
    if(!isDiff){
        cout<<first;
        return;
    }
    
    cout<<'(';
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int nr = r + (N/2)*i;
            int nc = c + (N/2)*j;
            func(N/2,nr,nc);
        }
    }
    cout<<')';
}