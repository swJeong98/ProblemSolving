/*BOJ 15666번 N과 M(12) - 2022.01.19*/
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[8];
int NUMS[8];
void func(int num); 
int getIndex(int target);

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
    int start;
    if(num ==0) start = 0;
    else start = getIndex(arr[num-1]);

    for(int i=start;i<N;i++){
        if(SameCheck != NUMS[i]) {
            SameCheck = arr[num] = NUMS[i];
            func(num+1);      
        }
    }
}

int getIndex(int target){
    for(int i=0;i<N;i++){
        if(NUMS[i]==target) return i;
    }
    return 0;
}