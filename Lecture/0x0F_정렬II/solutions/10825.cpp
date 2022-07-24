/* BOJ 10825 국영수 - 2021.09.26 */
#include <iostream>
#include <algorithm>
using namespace std;

class student {
public:
	string name;
	int kor;
	int eng;
	int mat;
public:
	friend ostream& operator<<(ostream& out, const student& s);
};

bool check(student a, student b);

ostream& operator<<(ostream& out, const student& s) {
	out << s.name;
	return out;
}

student arr[100000];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].mat;
	}
	sort(arr, arr + N, check);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}

bool check(student a, student b) {
	if (a.kor != b.kor) {
		return a.kor > b.kor;
	}
	else {
		if (a.eng != b.eng) {
			return !(a.eng > b.eng);
		}
		else {
			if (a.mat != b.mat) {
				return a.mat > b.mat;
			}
			else {
				return a.name.compare(b.name) < 0;
			}
		}
	}
}