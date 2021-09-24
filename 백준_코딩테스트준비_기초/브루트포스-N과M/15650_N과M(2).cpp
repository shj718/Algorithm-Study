#include <iostream>
#define MAX 8
using namespace std;

int arr[MAX];
bool visited[MAX + 1];
int N, M;

void print() {
	for (int i = 0; i < M; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}

void dfs(int start, int cnt) {
	if (cnt == M) {
		print();
		return;
	}
	for (int i = start; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}
