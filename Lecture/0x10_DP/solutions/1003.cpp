/*BOJ 1003번 피보나치 함수 - 2022.02.08*/
#include <iostream>
using namespace std;

pair<int,int> freq[41];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int T; cin>>T;
    freq[0].first = 1, freq[0].second = 0;
    freq[1].first = 0, freq[1].second = 1;
    for(int i=2;i<=40;i++){
        freq[i].first = freq[i-1].first + freq[i-2].first;
        freq[i].second = freq[i-1].second + freq[i-2].second;
    }
    while(T--){
        int N; cin>>N;
        cout<<freq[N].first<<' '<<freq[N].second<<'\n';
    } 
} 