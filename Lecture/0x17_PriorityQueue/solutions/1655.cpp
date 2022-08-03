/* BOJ 1655 가운데를 말해요 - 2022.07.23 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i=0;i<N;i++){
        int cur; cin>>cur;
        if(pq1.size() > pq2.size()) pq2.push(cur);
        else pq1.push(cur);

        if(!pq1.empty() && !pq2.empty()){
            if(pq1.top() > pq2.top()){
                int v1 = pq1.top();
                int v2 = pq2.top();
                pq1.pop(); 
                pq2.pop();
                pq1.push(v2);
                pq2.push(v1);
            }
        }
        cout<<pq1.top()<<'\n';
    }
    return 0;
}