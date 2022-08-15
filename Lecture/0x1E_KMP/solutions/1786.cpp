/* BOJ 1786 찾기 - 2022.08.01 */
#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(const string& pattern){
    int N = pattern.size();

    int begin = 1, matched = 0;
    vector<int> pi(N, 0);

    while(begin + matched < N){
        if(pattern[begin+matched] == pattern[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> KMP_Search(const string& text, const string& pattern){
    int N = text.size(), M = pattern.size();

    int begin = 0, matched = 0;
    vector<int> ans;
    vector<int> pi = getPartialMatch(pattern);

    while(begin <= N-M){
        if(matched < M && text[begin+matched] == pattern[matched]){
            matched++;
            if(matched == M) ans.push_back(begin);
        }
        else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string T, P; 
    getline(cin, T);
    getline(cin, P);
    vector<int> res = KMP_Search(T, P);

    cout<<res.size()<<'\n';
    for(auto elem : res) cout<<elem+1<<' ';
    return 0;
}
