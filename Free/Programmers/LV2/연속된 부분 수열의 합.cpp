#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    int l = 0, r = 0;
    int sum = sequence[l];
    int len = 1e6 + 10;
    
    pair<int,int> tmp;
    
    int N = (int)sequence.size();
    
    while(l <= r && r < N) {
        if(sum < k) {
            r++;
            if(r < N) sum += sequence[r];
        }
        else if(sum == k) {
            if(len > r-l+1) {
                tmp.first = l;
                tmp.second = r;
                len = r-l+1;
            }
            if(l == r) break;
            sum -= sequence[l++];
        }
        else{
            sum -= sequence[l++];
        }
    }

    
    vector<int> ans;
    ans.push_back(tmp.first);
    ans.push_back(tmp.second);
    return ans;
}
