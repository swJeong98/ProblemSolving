/*BOJ 15654 N과 M(5) - 2022.01.17*/
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int NUMS[8];
bool isUsed[8];
int arr[8];
void func(int num);
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>NUMS[i];
    sort(NUMS,NUMS+N);
    func(0);
    //cout<<ans;
}

void func(int num){
    if(num==M){
        for(int i=0;i<M;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        ans++;
        return;
    }

    for(int i=0;i<N;i++){
        if(!isUsed[i]){
            arr[num] = NUMS[i];
            isUsed[i] = true;
            func(num+1);
            isUsed[i] = false;
        }
    }
}