/*BOJ 11729번 하노이 탑 이동 순서 - 2021.01.17*/
#include <iostream>
#include <cmath>
using namespace std;

void HanoiMove(int N,int from,int to);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    cout<< (1<<N)-1 <<'\n';
    HanoiMove(N,1,3);
}

void HanoiMove(int N,int from,int to){
    if(N==1){
        cout<<from<<' '<<to<<"\n";
        return;
    }
    HanoiMove(N-1,from,6-from-to);
    cout<<from<<' '<<to<<"\n";
    HanoiMove(N-1,6-from-to,to);
}