/*BOJ 15650번 N과 M(2) - 2022.01.17*/
#include <iostream>
using namespace std;

int N,M;
int arr[8];
bool isUsed[9];
void func(int num);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    func(0);
}

void func(int num){
    if(num==M){
        for(int i=0;i<M;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    
    int start = arr[num-1]+1;
    for(int i=start;i<=N;i++){
        if(!isUsed[i]){
            isUsed[i] = true;
            arr[num] = i;
            func(num+1);
            isUsed[i] = false;
        }
    }
}