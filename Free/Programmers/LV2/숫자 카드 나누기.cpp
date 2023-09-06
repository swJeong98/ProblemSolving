#include <bits/stdc++.h>
using namespace std;

//x의 모든 약수 반환
vector<int> convert(int x) {
    vector<int> ret;
    for(int i=2; i<=x; i++) {
        if(x % i == 0) ret.push_back(i);
    }
    
    return ret;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    int minA = *min_element(arrayA.begin(), arrayA.end());
    int minB = *min_element(arrayB.begin(), arrayB.end());
    
    vector<int> numsA = convert(minA);
    vector<int> numsB = convert(minB);
    
    int mx = 0;
    for(int num : numsA) {
        bool flag = true;
        for(int a : arrayA) {
            if(a % num) {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(int b : arrayB) {
            if(b % num == 0) {
                flag = false;
                break;
            }
        }
        
        if(flag) mx = max(mx, num);
    }
    
    for(int num : numsB) {
        bool flag = true;
        for(int b : arrayB) {
            if(b % num) {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(int a : arrayA) {
            if(a % num == 0) {
                flag = false;
                break;
            }
        }
        if(flag) mx = max(mx, num);
    }
    
    //주어진 조건을 만족하는 가장 큰 양의 정수 a를 리턴, 없다면 0을 리턴
    return mx;
}
