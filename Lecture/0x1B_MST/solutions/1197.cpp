#include <iostream>
using namespace std;

class Edge {
public:
	int A;
	int B;
	int weight;
	bool operator<=(const Edge& e) {
		if (weight <= e.weight) return true;
		else return false;
	}
};

Edge arr1[100001];
Edge arr2[100001];
int Root[10001];
int edgeCnt;
int VertexCnt;

void merge(int left, int mid, int right) {
	int a = left;
	int b = mid + 1;
	int k = left;

	while (a <= mid && b <= right) {
		if (arr1[a] <= arr1[b]) arr2[k++] = arr1[a++];
		else arr2[k++] = arr1[b++];
	}

	if (a > mid) {
		for (int i = b; i <= right; i++) {
			arr2[k++] = arr1[i];
		}
	}
	else {
		for (int i = a; i <= mid; i++) {
			arr2[k++] = arr1[i];
		}
	}

	//여기를 왜 left, right로 설정해야되는지 정당성 따져보기 
	for (int i = left; i <= right; i++) {
		arr1[i] = arr2[i];
	}
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int find(int x) {
	if (Root[x] == x) return x;
	else {
		return Root[x] = find(Root[x]);
	}
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	Root[y] = x;
}

int main()
{
	//Spanning Tree는 Vertex의 개수보다 하나 작을 때 모두 연결될 수 있다.

	int weightCnt = 0;
	int checkCnt = 0;
	int idx = 1;
	int res1, res2;

	cin >> VertexCnt >> edgeCnt;
	int finishCnt = VertexCnt - 1;

	for (int i = 1; i <= edgeCnt; i++) {
		cin >> arr1[i].A >> arr1[i].B >> arr1[i].weight;
	}

	//가중치 간 정렬에는 merge_sort를 활용하였다.
	merge_sort(1, edgeCnt);
;
	//Root 노드는 각자 자기 번호로 초기화 하였다.
	for (int i = 1; i <= VertexCnt; i++) {
		Root[i] = i;
	}
	
	while (checkCnt < finishCnt) {

		res1 = find(arr1[idx].A);
		res2 = find(arr1[idx].B);

		if (res1 != res2) {
			Union(arr1[idx].A, arr1[idx].B);
			weightCnt += arr1[idx].weight;
			checkCnt++;
		}
		idx++;
	}
	cout << weightCnt;
}
