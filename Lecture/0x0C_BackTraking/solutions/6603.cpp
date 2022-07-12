/*BOJ 6033번 로또 - 2022.01.20*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
const int M = 6;
int Set[12];
int Arr[M];
bool isUsed[12];

void func(int num);
int getIndex(int target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> N; if (N == 0) return 0;
        for (int i = 0; i < N; i++) cin >> Set[i];
        func(0);
        cout << '\n';
        fill(isUsed, isUsed + N, false);
        fill(Arr, Arr + M, 0);
    }
}

void func(int num) {
    if (num == M) {
        for (int i = 0; i < M; i++) cout << Arr[i] << ' ';
        cout << '\n';
        return;
    }

    int start;
    if (num == 0) start = 0;
    else start = getIndex(Arr[num - 1]) + 1;
    for (int i = start; i < N; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            Arr[num] = Set[i];
            func(num + 1);
            isUsed[i] = false;
        }
    }
}

int getIndex(int target) {
    for (int i = 0; i < N; i++) {
        if (Set[i] == target) return i;
    }
    return 0;
}