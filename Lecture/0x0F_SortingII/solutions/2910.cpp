/*BOJ 2910번 빈도 정렬 - 2022.01.26*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
    return p1.second>p2.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,C; cin>>N>>C;
    for(int i=0;i<N;i++){
        bool check = false;
        int tmp; cin>>tmp;
        for(auto& a : v){
            if(a.first == tmp){
                check = true;
                a.second++;
                break;
            }
        }
        if(!check) v.push_back({tmp,1});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(auto& a: v){
        for(int i=0;i<a.second;i++) cout<<a.first<<' ';
    }
}