#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 7
using namespace std;

vector<int> v;
int N, M;
int arr[MAX];

void print() {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

void dfs(int cnt) {
	if (cnt == M) {
		print();
		return;
	}
	for (int i = 0; i < N; ++i) {
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0);
	return 0;
}
