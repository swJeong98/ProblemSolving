#include <bits/stdc++.h>
using namespace std;


bool isRight(string s){
    bool isRight = true;
    stack<int> stk;
    for(auto ch : s){
        if(ch=='(' || ch=='[') stk.push(ch);
        if(ch==')'){
            if(stk.empty()){
                isRight = false; break;
            }
            if(stk.top() == '(') {
                stk.pop(); continue;
            }
            isRight = false; break;
        }
        if(ch==']'){
            if(stk.empty()){
                isRight = false; break;
            }
            if(stk.top() == '[') {
                stk.pop(); continue;
            }
            isRight = false; break;
        }
    }
    if(stk.empty() && isRight) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        string s; cin>>s;
        cout<< ( isRight(s) ? "YES\n" : "NO\n" );
    }
}