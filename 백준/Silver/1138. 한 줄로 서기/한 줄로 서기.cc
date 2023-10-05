/* BOJ 1138 한 줄로 서기 - 2023.10.06*/
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<int> t;

bool check() {
    for(int i=1; i<=N; i++) {
        int cur = v[i];
        int cnt = 0;
        int pos = -1;
        for(int j=1; j<=N; j++) {
            if(t[j] == i) pos = j;
        }
        for(int j=1; j<=pos-1; j++) {
            if(t[j] > i) cnt += 1;
        }
        if(cnt != cur) return false;
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    v.resize(N+1);
    for(int i=1; i<=N; i++) {
        cin>>v[i];
    }

    t.resize(N+1);
    for(int i=1; i<=N; i++) {
        t[i] = i;
    }

    do{
        if(check()) {
            for(const auto& e : t) {
                if(e == 0) continue;
                cout<<e<<' ';
            }
            return 0;
        }
    }while(next_permutation(t.begin()+1, t.end()));


    return 0;   
}
