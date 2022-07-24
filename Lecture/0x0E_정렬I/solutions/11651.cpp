#include <iostream>
#include <algorithm>
using namespace std;

class Dot {
public:
	int x;
	int y;
public:
	bool operator<(const Dot& d) const {
		if (y < d.y) {
			return true;
		}
		else if (y == d.y) {
			return x < d.x;
		}
		else return false;
	}
	friend ostream& operator<<(ostream& out, const Dot& d);
};

ostream& operator<<(ostream& out, const Dot& d) {
	out << d.x << " " << d.y;
	return out;

}

Dot dotarr[100000];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dotarr[i].x >> dotarr[i].y;
	}

	sort(dotarr, dotarr + N);

	for (int i = 0; i < N; i++) {
		cout << dotarr[i] << "\n";
	}
}