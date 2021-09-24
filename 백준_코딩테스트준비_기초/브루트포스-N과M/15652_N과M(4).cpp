#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, M;

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
	for (int i = start; i <= N; ++i) {
		v.push_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}
