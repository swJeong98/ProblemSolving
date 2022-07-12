/*BOJ 1182번 부분 수열의 합- 2022.01.17*/
#include <iostream>
using namespace std;

int N,S;
int NUMS[20];
int ans;
void func(int idx,int sum); //idx번째 원소를 더할지 결정하는 함수(더한다면 sum에 더함)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>NUMS[i];
    func(0,0);
    if(S==0) ans--; // 처음 S가 0이면 시작부터 1이증가되기 때문임.
    cout<<ans;
}

void func(int idx,int sum){
    if(idx==N) {
        if(sum==S) ans++;
        return;
    }
    func(idx+1,sum+NUMS[idx]);
    func(idx+1,sum);
}