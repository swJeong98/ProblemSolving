/*BOJ 1629번 곱셈 - 2021.01.17*/
#include <iostream>
using namespace std;

long long pow(long long,long long,long long);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long A,B,C;
    cin>>A>>B>>C;
    cout<<pow(A,B,C);
}

long long pow(long long a,long long b,long long m){
    if(b==1) return a%m; //base condition
    if(b%2){ // b가 홀수
       long long val = pow(a,b/2,m);
       val *= val;
       val %= m;
       val *= a;
       val %= m;
       return val;
    }else{ //b가 짝수
        long long val = pow(a,b/2,m);
        val *= val;
        val %= m;
        return val;
    }
}