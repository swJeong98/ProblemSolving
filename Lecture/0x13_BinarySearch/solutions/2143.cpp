/*BOJ 2143 두 배열의 합 - 2022.03.13*/
#include <bits/stdc++.h>
using namespace std;

int A[1005];
int B[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T;
    int N; cin>>N;
    //A의 모든 부분 배열 합 구하기
    vector<int> sum1;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        sum1.push_back(A[i]);
    }
    for(int i=1;i<=N;i++){
        int tmp = A[i];
        for(int j=i+1;j<=N;j++){
            tmp += A[j];
            sum1.push_back(tmp);
        }
    }
    sort(sum1.begin(),sum1.end());

    //B의 모든 부분 배열 합 구하기
    int M; cin>>M;
    vector<int> sum2;
    for(int i=1;i<=M;i++){
        cin>>B[i];
        sum2.push_back(B[i]);
    }
    for(int i=1;i<=M;i++){
        int tmp = B[i];
        for(int j=i+1;j<=M;j++){
            tmp += B[j];
            sum2.push_back(tmp);
        }
    }

    //답 구하기
    long long ans = 0;
    for(auto cur : sum2){
        int diff = T - cur;
        auto st = lower_bound(sum1.begin(),sum1.end(),diff);
        auto en = upper_bound(sum1.begin(),sum1.end(),diff);
        ans += (en-st);
    }
    cout<<ans;
    return 0;
}