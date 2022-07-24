/*BOJ 1181번 단어 정렬 - 2022.01.26*/
#include <iostream>
#include <algorithm>
using namespace std;

string word[20000];
bool cmp(const string& s1,const string& s2){
    if(s1.size() != s2.size()) return s1.size()<s2.size();
    return s1.compare(s2)<0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>word[i];
    sort(word,word+N,cmp);
    string cur="";
    for(int i=0;i<N;i++){
        if(cur != word[i]) {
            cout<<word[i]<<'\n';
            cur = word[i];
        }
    }
}