/* BOJ 16637 괄호 추가하기 - 2022.08.24 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll ans = -0x7FFFFFFF;
string expression;
vector<int> op;
vector<bool> check;

ll calculate(char _a, char _b, char ch){
    int a = _a - '0', b = _b - '0';

    if(ch == '*') return (ll)a * (ll)b;
    else if(ch == '+') return (ll)a + (ll)b;
    return (ll)a - (ll)b;
}

void solve(int idx){
    if(idx == (int)op.size()){
        stack<ll> st;
        stack<char> st2;

        for(int i=1;i<(int)expression.size(); i+=2){
            if(check[i/2]){
                ll tmp = calculate(expression[i-1], expression[i+1], expression[i]);
                st.push(tmp);
                i += 2;
            }
            else st.push((ll)(expression[i-1] - '0') );

            if(st.size() == 2){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                char ch = st2.top(); st2.pop();
                if(ch == '*') st.push((ll)a * (ll)b );
                else if(ch == '+') st.push((ll)a + (ll)b );
                else st.push((ll)a - (ll)b);
            }
            if(i < (int)expression.size()) st2.push(expression[i]);
        }
        ll res;
        if(st.size() == 2){
            ll b = st.top(); st.pop();
            ll a = st.top(); st.pop();
            char ch = st2.top(); st2.pop();
            if(ch == '*') res = a * b;
            else if(ch == '+') res = a+b;
            else res = a-b;
        }
        else{
            if(st2.empty()) res = st.top();
            else{
                char ch = st2.top(); st2.pop();
                if(ch == '*') res = st.top() * (ll)(expression[N-1] - '0');
                else if(ch == '+') res = st.top() + (ll)(expression[N-1] - '0');
                else res = st.top() - (ll)(expression[N-1] - '0');
            }
        }
        ans = max(ans, res);
        return;
    }
    if(idx == 0){
        check[idx] = true;
        solve(idx + 1);
        check[idx] = false;
        solve(idx + 1);
    }
    else{
        if(check[idx-1]) solve(idx + 1);
        else {
            check[idx] = true;
            solve(idx + 1);
            check[idx] = false;
            solve(idx + 1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>expression;
    if(N == 1) {
        cout<<expression[0] - '0';
        return 0;
    }

    for(int i=1;i<(int)expression.size();i+=2) op.push_back(i);

    check.resize((int)op.size(), false);

    solve(0);
    cout<<ans;
    return 0;
}
