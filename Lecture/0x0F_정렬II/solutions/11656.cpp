/*BOJ 11656번 접미사 배열 - 2022.01.26*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> list;
bool cmp(const string& s1,const string& s2){
    return s1<s2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        list.push_back(s.substr(i,s.size()));
    }
    sort(list.begin(),list.end(),cmp);
    for(auto s:list) cout<<s<<'\n';
}