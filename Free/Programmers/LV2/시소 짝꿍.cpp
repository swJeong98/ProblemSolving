#include <bits/stdc++.h>
#define ll long long
using namespace std;

//nC2 계산
ll comb(ll n, ll x) {
    return n * (n-1) / 2;    
}

ll solution(vector<int> weights) {
    
    ll ans = 0;
    
    sort(weights.begin(), weights.end());
    
    ll duplicated = 0;
    int pre = -1;
    for(int i=0; i<weights.size(); i++) {
        int cur = weights[i];
        
        //자신과 동일한 원소 찾기
        if(pre != cur) {
            ll cnt = 
            (ll) (upper_bound(weights.begin(), weights.end(), cur) - 
            lower_bound(weights.begin(), weights.end(), cur));
            duplicated += comb(cnt, 2);   
        }
        pre = cur;
        
        //자신과 다른 원소 찾기
        //cur * 2
        int tmp = cur * 2;
        if(tmp % 3 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/3) - 
                lower_bound(weights.begin(), weights.end(), tmp/3));
        }
        if(tmp % 4 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/4) -
                lower_bound(weights.begin(), weights.end(), tmp/4));
        }
        
        //cur * 3
        tmp = cur * 3;
        if(tmp % 2 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/2) - 
                lower_bound(weights.begin(), weights.end(), tmp/2));
        }
        if(tmp % 4 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/4) -
                lower_bound(weights.begin(), weights.end(), tmp/4));
        }
        
        //cur * 4
        tmp = cur * 4;
        if(tmp % 2 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/2) - 
                lower_bound(weights.begin(), weights.end(), tmp/2));
        }
        if(tmp % 3 == 0) {
            ans += (ll)(upper_bound(weights.begin(), weights.end(), tmp/3) -
                lower_bound(weights.begin(), weights.end(), tmp/3));
        }
        
    }
    
    //시소 짝꿍이 이루어지는 쌍의 개수 리턴
    return duplicated + (ans/2);
}
