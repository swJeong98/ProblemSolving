/*BOJ 2504 괄호의 값- 2022.03.15*/
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
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin>>s;
    if(!isRight(s)){
        cout<<0; return 0;
    }
    //올바른 괄호 문자열만 이 로직을 진행함.
    stack<int> st;
    //'(' = -2, '[' = -3 로 간주한다.
    for(size_t i=0; i<s.size(); i++){
        if(s[i] == '(') st.push(-2);
        if(s[i] == ')') {
            int tmp = 0;
            if(st.top() == -2) tmp = 1;
            else{
                while(st.top() != -2){
                    tmp += st.top();
                    st.pop();
                }
            }
            st.pop();
            st.push(2*tmp);
        }
        if(s[i] == '[') st.push(-3);
        if(s[i] == ']') {
            int tmp = 0;
            if(st.top() == -3) tmp = 1;
            else{
                while(st.top() != -3){
                    tmp += st.top();
                    st.pop();
                }
            }
            st.pop();
            st.push(3*tmp);
        }
    }
    int ans = 0;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout<<ans;
    return 0;
}