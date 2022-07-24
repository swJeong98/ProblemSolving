/*BOJ 1431번 시리얼 번호 - 2022.01.26*/
#include <iostream>
#include <algorithm>
using namespace std;

string sNum[50];
int getSum(const string& s){
    int ret=0;
    for(size_t i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') ret += (s[i]-'0');
    }
    return ret;
}
bool cmp(const string& s1,const string& s2){
    if(s1.size() != s2.size()) return s1.size()<s2.size();
    else {
        int res1 = getSum(s1); 
        int res2 = getSum(s2);
        if(res1 != res2) return res1<res2;
    }
    return s1.compare(s2)<0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>sNum[i];
    sort(sNum,sNum+N,cmp);
    for(int i=0;i<N;i++) cout<<sNum[i]<<'\n';
}