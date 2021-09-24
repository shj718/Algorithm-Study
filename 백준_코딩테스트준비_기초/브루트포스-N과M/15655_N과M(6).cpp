#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

vector<int> v;
int N, M;
int arr[MAX];
bool visited[MAX];

void print() {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

void dfs(int start, int cnt) {
	if (cnt == M) {
		print();
		return;
	}
	for (int i = start; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			dfs(i, cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0, 0);
	return 0;
}
