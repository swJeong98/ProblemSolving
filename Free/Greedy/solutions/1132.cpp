/* BOJ 1132 합 -  2022.07.05 */
#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

bool isFirst[15], appear[15];
pair<ll, ll> check[15]; 
ll val[15];

bool cmp(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    if(p1.X != p2.X) return p1.X > p2.X;
    return p1.Y > p2.Y;
}

int main()
{ 
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        string s; cin>>s;
        for(int j=0;j<(int)s.size();j++){
            if(j==0) isFirst[s[j] - 'A'] = true;
            appear[s[j]- 'A'] = true;
            ll exp = (int)s.size() - (j+1); //현재 보고 있는 숫자는 10의 몇 제곱인지 판단
            check[s[j] - 'A'].X += (ll)pow(10, exp); 
        }
    }
    for(ll i=0;i<10;i++) check[i].Y = i;
    sort(check, check+10, cmp);
    
    //등장한 알파벳 개수 판단
    int cnt = 0;
    for(int i=0;i<10;i++) {
        if(appear[i]) cnt++;
    }

    if(cnt < 10){
        ll mx = 9;
        for(int i=0;i<10;i++){
            if(!appear[check[i].Y]) continue;
            val[check[i].Y] = mx;
            mx -= 1;
        }
    }
    else{ //cnt == 10
        //처음에 등장하지 않는 것 찾기
        vector<ll> v;
        for(int i=0;i<10;i++){
            if(!isFirst[i]) v.push_back((ll)i);
        }
        //0이 될 알파벳 정하기
        ll mn = 1e15;
        ll idx = -1;
        for(auto elem : v){
            for(int i=0;i<10;i++){
                if(check[i].Y == elem && mn > check[i].X){
                    mn = check[i].X;
                    idx = check[i].Y;
                }
            }
        }
        val[idx] = 0;

        ll mx = 9;
        for(int i=0;i<10;i++){
            if(check[i].Y == idx) continue;
            val[check[i].Y] = mx;
            mx--;
        }
    }

    ll ans = 0;
    for(int i=0;i<10;i++){
        if(!appear[check[i].Y]) continue;
        ans += (check[i].X * val[check[i].Y]);
    }
    cout<<ans;

    // for(int i=0;i<10;i++) cout<<check[i].X<<' '<<check[i].Y<<'\n';
    return 0;
}