#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int kthElement(int storey, int k) {
    return (to_string(storey)[k-1]) - '0';
}

int solution(int storey) {
    int ans = 0;
    
    int len = to_string(storey).size();
    
    for(int i=1; i<len; i++) {
        int mod = storey % tens[i];
        int down = mod / tens[i-1];
        int up = 10 - down;
        
        if(up > down) {
            ans += down;
            storey -= (down * tens[i-1]);
        }else if(up == down) {
            int elem = kthElement(storey, i+1);
            if(elem < 5) {
                ans += down;
                storey -= (down * tens[i-1]);
            }else{
                ans += up;
                storey += (up * tens[i-1]);
            }
        }else{
            ans += up;
            storey += (up * tens[i-1]);
        }
        
    }
    
    cout << storey;
    int endLen = to_string(storey).size();
    
    int add = storey / tens[endLen-1];
    add = min(add, (10-add)+1);
    
    ans += add;
    //최소 이동 횟수를 리턴
    return ans;
}
