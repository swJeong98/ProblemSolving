/*BOJ 1931 회의실 배정 - 2022.02.10*/
#include <iostream>
#include <algorithm>
#define st first
#define end second
using namespace std;

pair<int,int> a[100000];

bool cmp(pair<int,int>& p1,pair<int,int>& p2){
    if(p1.end != p2.end) return p1.end<p2.end;
    return p1.st<p2.st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>a[i].st>>a[i].end;
    sort(a,a+N,cmp);
     
    int ans = 1;
    int fin = a[0].end;
    for(int i=1;i<N;i++){
        if(fin<=a[i].st){
            ans++;
            fin = a[i].end;
        }
    }
    cout<<ans;
}