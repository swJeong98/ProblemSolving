/*BOJ 11279번 최대 힙 - 2022.02.25*/
#include <iostream>
using namespace std;

int cmp1(int d1, int d2) {
    if (d1 > d2) return 1;
    else if (d1 == d2) return 0;
    else return -1;
}

class pq {
public:
    int (*cmp) (int d1, int d2) = cmp1;
    int numofdata = 0;
    int arr[100005] = {};
    bool isEmpty() {
        return numofdata == 0;
    }
    void push(int data) {
        int idx = numofdata + 1;
        while (idx != 1) {
            if (cmp(data, arr[idx / 2]) > 0) {
                arr[idx] = arr[idx / 2];
                idx /= 2;
            }
            else break;
        }
        arr[idx] = data;
        numofdata++;
    }
    int getHighChild(int parent) {
        if (parent * 2 > numofdata) return 0;
        else if (parent * 2 == numofdata) return parent * 2;
        else {
            if (cmp(arr[parent * 2], arr[1 + parent * 2]) > 0) {
                return parent * 2;
            }
            else return 1 + parent * 2;
        }
    }
    int pop() {
        int idx = 1;
        int child;
        int retData = arr[1];
        int last = arr[numofdata];

        while (child = getHighChild(idx)) {
            if (cmp(last, arr[child]) < 0) {
                arr[idx] = arr[child];
                idx = child;
            }
            else break;
        }
        arr[idx] = last;
        numofdata--;
        return retData;
    }
};

pq pq1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int com; cin >> com;
        if (com == 0) {
            if (pq1.isEmpty()) cout << 0 << '\n';
            else cout << pq1.pop() << '\n';
            continue;
        }
        pq1.push(com);
    }
}