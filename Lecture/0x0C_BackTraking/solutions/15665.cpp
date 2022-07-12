/*BOJ 15665번 N과 M(11) - 2022.01.19*/
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[8];
int NUMS[8];
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
    
    int SameCheck = 0;
    for(int i=0;i<N;i++){
        if(SameCheck != NUMS[i]) {
            SameCheck = arr[num] = NUMS[i];
            func(num+1);      
        }
    }
}