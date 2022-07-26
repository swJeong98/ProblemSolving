/*BOJ 1920 수 찾기 - 2022.03.11*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,M; cin>>N;
    map<int,int> mp;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        mp[x]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int x; cin>>x;
        if(mp[x] > 0) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}