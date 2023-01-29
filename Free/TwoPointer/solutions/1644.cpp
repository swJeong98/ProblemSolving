/* BOJ 1644 소수의 연속합- 2023.01.12 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1, true);
    state[1] = false;
    for(int i=2; i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i; j<= n; j+= i) state[j] = false;
    }
    for(int i=2;i<=n;i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    vector<int> primes = sieve(N);

    int l = 0, r = 0;
    int tot = 2;
    int ans = 0;

    while(r < primes.size()) {
        if(tot < N) {
            r += 1;
            if(r < primes.size()) tot += primes[r];
        }else if(tot == N) {
            ans += 1;
            if(l == r) {
                l++; r++;
                if(r < primes.size()) tot = primes[r];
            }
            else {
                tot -= primes[l];
                l++;
            }
        }else{
            if(l == r) {
                l++; r++;
                if(r < primes.size()) tot = primes[r];
            }
            else {
                tot -= primes[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}