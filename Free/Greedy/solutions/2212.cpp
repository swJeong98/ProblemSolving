/*BOJ 2212번 센서 - 2022.03.01*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K; cin>>N>>K;
    vector<int> pos;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        pos.push_back(tmp);
    }
    sort(pos.begin(),pos.end());
    
    vector<int> interval;
    for(vector<int>::iterator it = pos.begin(); it!=pos.end();it++){
        if(it==pos.begin()) continue;
        interval.push_back(*it - *(it-1));
    }
    sort(interval.begin(),interval.end());
    int iter = N-K;
    int ans = 0;
    for(int i=0;i<iter;i++){
        ans += interval[i];
    }
    cout<<ans;
}