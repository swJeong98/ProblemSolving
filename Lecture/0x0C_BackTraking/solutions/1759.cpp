/*BOJ 1759번 암호 만들기 - 2022.01.20*/
#include <iostream>
#include <algorithm>
using namespace std;

int L,C;
char arr[15];
char base[15];

void func(int num,int cnt1,int cnt2); // cnt1: 모음 개수, cnt2:자음개수
bool isVowels(char c); //모음인지 확인하는 함수.
int getIndex(char target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>L>>C;
    for(int i=0;i<C;i++) cin>>base[i];
    sort(base,base+C);
    func(0,0,0);
}

void func(int num,int cnt1,int cnt2){
    if(num==L){
        if(cnt1>=1 && cnt2>=2){
            for(int i=0;i<L;i++) cout<<arr[i];
            cout<<'\n';
        }
        return;
    }
    
    int start;
    if(num==0) start = 0;
    else start = getIndex(arr[num-1])+1;
    
    for(int i=start;i<C;i++){
        arr[num] = base[i];
        if(isVowels(base[i])) func(num+1,cnt1+1,cnt2);
        else func(num+1,cnt1,cnt2+1);
    }
}

bool isVowels(char c){
    if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u') return true;
    return false;
}

int getIndex(char target){
    for(int i=0;i<C;i++){
        if(base[i]==target) return i;
    }
    return 0;
}