/*BOJ 2295 세 수의 합- 2022.03.17*/
#include <bits/stdc++.h>
using namespace std;

vector<int> U(1005);
vector<int> two;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>U[i];
    
    // (a[i] + a[j] ) + a[k] = a[l]
    // (a[i] + a[j]) 먼저 구함.
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            int tmp = U[i] + U[j];
            two.push_back(tmp);
        }
    }
    sort(two.begin(), two.end());
    //a[l] - a[k] 중 a[i] + a[j] 값 있는지 이분 탐색
    int mx = 0;
    for(int l=0; l<N; l++){
        for(int k=0; k<N; k++){
            int tmp = U[l] - U[k];
            bool Exist = binary_search(two.begin(),two.end(),tmp);
            if(Exist) mx = max(mx,U[l]);
        }
    }
    cout<<mx;
    return 0;
}