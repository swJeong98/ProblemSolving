/*BOJ 1074번 Z - 2021.01.17*/
#include <iostream>
using namespace std;

int func(int,int,int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,r,c;
    cin>>N>>r>>c;
    cout<<func(N,r,c);
}

int func(int N,int r,int c){
    if(N==0) return 0;
    int half = 1<<N-1; //2^N-1
    if(r<half && c<half) return func(N-1,r,c);
    if(r<half && c>=half) return half*half + func(N-1,r,c-half);
    if(r>=half && c<half) return half*half*2 + func(N-1,r-half,c);
    return half*half*3 + func(N-1,r-half,c-half);
}