/* BOJ 8980 택배 - 2022.09.02 */
#include <bits/stdc++.h>
using namespace std;

typedef struct box{
    int src, dst, w;
}box;

box b[10005];
int weighted[2005];

bool cmp(const box& b1, const box& b2){
    if(b1.dst == b2.dst) return b1.src<b2.src;
    return b1.dst < b2.dst;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, C; cin>>N>>C;
    int M; cin>>M;
    for(int i=0;i<M;i++){
        cin>>b[i].src>>b[i].dst>>b[i].w;
    }
    sort(b, b+M, cmp);

    int ans = 0;
    for(int i=0;i<M;i++){
        int from = b[i].src;
        int to = b[i].dst;
        int capacity = b[i].w;
        int mx = 0;
        for(int j=from; j<to; j++){
            mx = max(mx, weighted[j]);
        }

        int t = min(capacity, C-mx);
        ans += t;
        for(int j=from; j<to; j++){
             weighted[j] += t;
        }
    }

    cout<<ans;
    return 0;
}
