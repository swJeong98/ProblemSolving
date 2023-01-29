#include <iostream>
using namespace std;

int NUMS[1000001];
bool occurs[2000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> NUMS[i];
    }
    int X; cin >> X;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (X - NUMS[i] > 0 && occurs[X - NUMS[i]]) count++;
        occurs[NUMS[i]] = true;
    }
    cout << count;
}