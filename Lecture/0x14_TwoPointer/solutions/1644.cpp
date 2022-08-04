/* BOJ 1644 소수의 연속합 - 2022.08.04 */
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
    int ans = 0;
    int sum = 2;

    while(r < primes.size()){
        if(sum < N){
            r += 1;
            sum += primes[r];
        }
        else if(sum == N){
            ans += 1;
            sum -= primes[l];
            l += 1;
        }
        else{
            sum -= primes[l];
            l += 1;
        }
    }
    cout<<ans;
    return 0;
}
