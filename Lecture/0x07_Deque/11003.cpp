/**
 * BOJ 11003 최솟값 찾기 - 2023.01.15
 */
#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, L; cin>>N>>L;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    for(int i=1;i<=N;i++){
        int cur; cin>>cur;
        pq.push({cur, i});

        int st = max(1, i-L+1);
        while(pq.top().second < st) pq.pop();

        cout<<pq.top().first<<' ';
    }
    return 0;
}