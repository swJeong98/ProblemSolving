/* BOJ 2457 공주님의 정원 - 2022.05.28 */
#include <bits/stdc++.h>
using namespace std;

class flower{
public:
	int smonth; //꽃 피는 달(start month)
	int sday;   //꽃 피는 날짜
	int emonth; //꽃 지는 달(end month)
	int eday;   //꽃 지는 날짜
};

bool cmp(const flower& f1, const flower& f2){
	if(f1.emonth != f2.emonth) return f1.emonth > f2.emonth;
	else if(f1.emonth == f2.emonth) return f1.eday > f2.eday;
	else if(f1.smonth != f2.smonth) return f1.smonth < f2.smonth;
	else return f1.sday < f2.sday;
}

flower A[100005];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int N; cin>>N;
	int cnt = 0; //12월 1일 이상의 지는 날짜의 꽃이 없다면 0을 출력해야 하기 때문에 그러한 꽃의 개수를 센다.
	for(int i=0;i<N;i++) {
		cin>>A[i].smonth>>A[i].sday>>A[i].emonth>>A[i].eday;
		if(A[i].emonth == 12) cnt++;
	}
	if(cnt == 0){
		cout<<0;
		return 0;
	}
	sort(A, A+N, cmp);

	int ans = 0;
	int em = 12, ed = 1; //12월 1일에 지는 꽃을 찾아야 최소한 11/30까지 꽃이 있는 것이 보장된다. 
	int sm = 13, sd = 35;
	for(int i=0;i<N;i++){
		flower cur = A[i];
		//현재 커트라인의 날짜를 넘을 수 있는지 확인
		if( (cur.emonth == em && cur.eday >= ed) || cur.emonth > em) {
			if( (cur.smonth == sm && cur.sday < sd) || cur.smonth < sm){
				sm = cur.smonth;
				sd = cur.sday;
			}
		}
		//그렇지 못하다면, 이제 새로운 커트라인이 필요
		else{
			ans += 1;
			em = sm, ed = sd;
			sm = 13, sd = 35;
			if( (cur.emonth == em && cur.eday >= ed) || cur.emonth > em){
				if( (cur.smonth == sm && cur.sday < sd) || cur.smonth < sm){
					sm = cur.smonth;
					sd = cur.sday;
				}
			}
		}

		if((sm == 3 && sd == 1) || sm < 3){
			ans += 1;
			cout<<ans;
			return 0;
		}
	}
	//여기에 도달했다는 것은 3월 1일에 꽃이 피어있을 수 없다는 의미이므로, 0을 출력한다.
	cout << 0;
	return 0;
}