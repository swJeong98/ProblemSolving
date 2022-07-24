#include <iostream>
using namespace std;

int arr[1000000];
int temp[1000000];
void Merge_sort(int start,int end);
void Merge(int start,int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    Merge_sort(0,N-1);
    for(int i=0;i<N;i++) cout<<arr[i]<<'\n';
}

void Merge_sort(int start,int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    Merge_sort(start,mid);
    Merge_sort(mid+1,end);
    Merge(start,end);
}

void Merge(int start,int end){
    int mid = (start+end)/2;
    int l = start;
    int r = mid+1;
    int cur = start;
    while(l<=mid && r<=end){
        if(arr[l]<=arr[r]) temp[cur++] = arr[l++];
        else temp[cur++] = arr[r++];
    }
    if(l<=mid){
        for(int i=l;i<=mid;i++) temp[cur++] = arr[i];
    }
    else{
        for(int i=r;i<=end;i++) temp[cur++] = arr[i];
    }
    
    for(int i=start;i<=end;i++) arr[i] = temp[i];
}