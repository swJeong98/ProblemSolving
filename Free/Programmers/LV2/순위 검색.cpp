#include <bits/stdc++.h>
using namespace std;

string str[4][4] ={{"-", "cpp", "java", "python"},
                   {"-", "backend", "frontend"},
                   {"-", "junior", "senior"},
                   {"-", "chicken", "pizza"}
                  };

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<int>> cache(108);
    
    int v[4] = {};
    for(int i=0; i<info.size(); i++) {
        string s = info[i];
        int idx1 = 0, idx2 = s.find(" ", idx1);
        for(int j=0; j<4; j++) {
            v[j] = find(str[j], str[j]+4, s.substr(idx1, idx2-idx1)) - str[j];
            idx1 = idx2+1;
            idx2 = s.find(" ", idx1);
        }
        
        int score = stoi(s.substr(idx1, 10));
        for(int a : {0, v[0]}) {
            for(int b : {0, v[1]}) {
                for(int c : {0, v[2]}) {
                    for(int d : {0, v[3]}) {
                        int pos = a * 27 + b * 9 + c * 3 + d;
                        cache[pos].push_back(score);
                    }
                }
            }
        }
    }
    
    for(int i=0; i<108; i++) sort(cache[i].begin(), cache[i].end());
    
    for(int i=0; i<query.size(); i++) {
        string s = query[i];
        int idx1 = 0, idx2 = s.find(" ", idx1);
        for(int j=0; j<4; j++) {
            v[j] = find(str[j], str[j]+4, s.substr(idx1, idx2-idx1)) - str[j];
            idx1 = idx2+5;
            idx2 = s.find(" ", idx1);
        }
        
        int score = stoi(s.substr(idx1-4, 10));
        int pos = v[0] * 27 + v[1] * 9 + v[2] * 3 + v[3];
        
        answer.push_back(cache[pos].end() - lower_bound(cache[pos].begin(), cache[pos].end(), score));
    }
    
    return answer;
}
