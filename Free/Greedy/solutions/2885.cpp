/* BOJ 2885 초콜릿 식사 - 2022.08.18 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int K; cin>>K;
    int chocolate = 1;
    int cnt = 0;
    while(chocolate < K){
        chocolate <<= 1;
        cnt += 1;
    }

    cout<<chocolate<<' ';
    if(chocolate == K) {cout<<0; return 0;}

    int tmp = K;
    int pos = 0;
    while(tmp > 0) {
        int bit = tmp % 2;
        if(bit == 1) break;
        pos += 1;
        tmp >>= 1;
    }
    cout<<cnt-pos;
    return 0;
}
