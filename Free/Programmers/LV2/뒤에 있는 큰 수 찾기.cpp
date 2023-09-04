#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    stack<pair<int,int>> st;
    
    vector<int> ans;
    
    for(int i=numbers.size()-1; i>=0; i--) {
        int cur = numbers[i];
        
        while(!st.empty() && cur >= st.top().Y) {
            st.pop();
        }
        
        if(st.empty()) {
            ans.push_back(-1);
        }else{
            ans.push_back(st.top().Y);
        }
        
        st.push({i, cur});
    }
    
    // 각 원소 별로 뒷 큰수를 벡터에 담아서 리턴
    // 거꾸로 되어있으므로 뒤집어서 리턴
    reverse(ans.begin(), ans.end());
    return ans;
}
