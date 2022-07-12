/*BOJ 15656번 N과 M(7) - 2022.01.17*/
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int NUMS[8];
int arr[8];
void func(int num);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>NUMS[i];
    sort(NUMS,NUMS+N);
    func(0);
}

void func(int num){
    if(num==M){
        for(int i=0;i<M;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++){
        arr[num] = NUMS[i];
        func(num+1);
    }
}