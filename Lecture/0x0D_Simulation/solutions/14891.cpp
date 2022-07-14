/* BOJ 14891 톱니바퀴 - 2022.05.03 */
#include <bits/stdc++.h>
using namespace std;

int wheel[5][10];
int direction[5];
bool isSpin[5];

//dir = 1 : 시계, dir = -1 :반시계
void spin(int num, int dir){
    if(num < 1 || num >4) return;

    if(dir == 1){
        int tmp = wheel[num][8];
        for(int i=8;i>=2;i--){
            wheel[num][i] = wheel[num][i-1];
        }
        wheel[num][1] = tmp;
    }
    else{ // dir == -1
        int tmp = wheel[num][1];
        for(int i=1;i<=7;i++){
            wheel[num][i] = wheel[num][i+1];
        }
        wheel[num][8] = tmp;
    }
    return;
}

void upd(int num,int dir){
    int l = num-1, r =num+1;
    
    int pre = num;
    int predir = dir;
    while(r != -1){
        if(r <= 4 && wheel[pre][3] != wheel[r][7]){
            isSpin[r] = true; direction[r] = -predir;
            pre = r; r += 1; predir = -predir;
        }
        else r = -1;
    }
    
    pre = num; 
    predir = dir;
    while(l != -1){
        if(l >= 1 && wheel[pre][7] != wheel[l][3]){
            isSpin[l] = true; direction[l] = -predir;
            pre = l; l -= 1; predir = -predir;
        }
        else l = -1;
    }
}

int getScore(){
    int rval = 0;
    if(wheel[1][1] == 1) rval += 1;
    if(wheel[2][1] == 1) rval += 2;
    if(wheel[3][1] == 1) rval += 4;
    if(wheel[4][1] == 1) rval += 8;
    return rval;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for(int i=1;i<=4;i++){
        string s; cin>>s;
        for(auto j=0;j<s.size();j++){
            wheel[i][j+1] = (s[j] - '0');
        }
    }
    
    int K; cin>>K;
    while(K--){
        int cur, dir; cin>>cur>>dir;
        fill(isSpin,isSpin+5,false);
        isSpin[cur] = true; 
        direction[cur] = dir;
        upd(cur, dir);
        for(int i=1;i<=4;i++){
            if(isSpin[i]){
                spin(i,direction[i]);
            }
        }
    }
    cout<<getScore();
}