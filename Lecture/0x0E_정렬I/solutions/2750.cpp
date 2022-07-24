/* BOJ 2750 수 정렬하기 - 2022.01.26 */
#include <iostream>
using namespace std;

int arr[1000];
void quick_sort(int start,int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    quick_sort(0,N-1);
    for(int i=0;i<N;i++) cout<<arr[i]<<'\n';
}

void quick_sort(int start,int end){
    if(start >= end) return;
    int pivot = arr[start];
    int left = start+1;
    int right = end;
    while(1){
        while(left<=right && arr[left]<=pivot) left++;
        while(left<=right && arr[right]>=pivot) right--;
        if(left>right) break;
        swap(arr[left],arr[right]);
    }
    swap(arr[start],arr[right]);
    quick_sort(start,right-1);
    quick_sort(right+1,end);
}