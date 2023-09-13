#include <bits/stdc++.h>
using namespace std;

//ch1 -> ch2로 변환하는데 필요한 최소 숫자
int calc(char ch1, char ch2) {
    int tmp = ch2 - ch1;
    return min(tmp, 26-tmp);
}

int solution(string name) {
    int N = name.size();
    int leftRight = N-1;
    int upDown = 0;
    
    for(int i=0; i<N; i++) {
        upDown += calc('A', name[i]);
        
        int idx = i+1;
        while(idx < N && name[idx] == 'A') idx++;
        
        int tmp = i + (N - idx) + min(i, N-idx);
        leftRight = min(leftRight, tmp);
    }
    
    return upDown + leftRight;
}
