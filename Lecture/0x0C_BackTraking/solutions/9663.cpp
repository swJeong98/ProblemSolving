/*BOJ 9663번 N-Queen - 2022.01.17*/
#include <iostream>
using namespace std;

int N;
int ans = 0;
bool isUsed1[15]; //동일한 열에 퀸이 있는지 저장하는 배열
bool isUsed2[29]; //우상향 대각선에 퀸이 있는지 저장하는 배열
bool isUsed3[28]; //우하향 대각선에 퀸이 있는지 저장하는 배열
void func(int R); //R번째 행에 놓을 퀸의 자리를 정하는 함수.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    func(1);
    cout<<ans;
}

void func(int R){
    if(R==N+1){ //base condition
        ans++;
        return;
    }

    for(int i=1;i<=N;i++){
        if(isUsed1[i] || isUsed2[R+i] || isUsed3[R-i+N] ) continue;
        isUsed1[i] = true;
        isUsed2[R+i] = true;
        isUsed3[R-i+N] = true;
        func(R+1);
        isUsed1[i] = false;
        isUsed2[R+i] = false;
        isUsed3[R-i+N] = false;
    }
}