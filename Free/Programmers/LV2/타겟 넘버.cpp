#include <bits/stdc++.h>
using namespace std;

int ans;
int T;

void dfs(const vector<int>& numbers, int idx, int sum) {
    if(idx == numbers.size()) {
        if(sum == T) {
            ans += 1;
        }
        return;
    }
    
    dfs(numbers, idx+1, sum+numbers[idx]);
    dfs(numbers, idx+1, sum-numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    T = target;
    dfs(numbers, 0, 0);
    
    return ans;
}
