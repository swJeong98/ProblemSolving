/* BOJ 1744 수 묶기- 2022.05.27 */
#include <bits/stdc++.h>
using namespace std;

vector<int> p, m, zero;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int x; cin>>x;
        if(x >0) p.push_back(x);
        else if(x == 0) zero.push_back(x);
        else m.push_back(x);
    }
    
    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end());
    
    int ans = 0;
    for(auto i=0; i<p.size(); i++){
        if(i == p.size() -1 || p[i] == 1) ans += p[i];
        else{
            if(p[i+1] != 1){
                ans += (p[i] * p[i+1]);
                i++;
            }
            else{
                ans += p[i];
            }
        }
    }

    for(auto i=0;i<m.size(); i++){
        if(i == m.size()-1){
            if(zero.size() >= 1) ans += 0;
            else ans += m[i];
        }
        else{
            ans += (m[i] * m[i+1]);
            i++;
        }
    }
    cout<<ans;
    return 0;
}