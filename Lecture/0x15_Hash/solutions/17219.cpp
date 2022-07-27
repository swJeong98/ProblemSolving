/*BOJ 17219번 비밀번호 찾기 - 2022.01.13*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	string site, password;
	map<string, string> mp;
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		mp[site] = password;
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << mp[site] << '\n';
	}
}