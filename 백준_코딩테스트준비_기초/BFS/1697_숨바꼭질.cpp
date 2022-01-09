#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int N, K;
bool visited[MAX];
int depth[MAX];

bool isValid(int x) {
	if (x >= 0 && x < MAX) return true;
	else return false;
}

void bfs(int start) {
	queue<int> q;
	int cur;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur == K) break;
		if (isValid(cur - 1) && visited[cur - 1] == 0) {
			q.push(cur - 1);
			visited[cur - 1] = true;
			depth[cur - 1] = depth[cur] + 1;
		}
		if (isValid(cur + 1) && visited[cur + 1] == 0) {
			q.push(cur + 1);
			visited[cur + 1] = true;
			depth[cur + 1] = depth[cur] + 1;
		}
		if (isValid(cur * 2) && visited[cur * 2] == 0) {
			q.push(cur * 2);
			visited[cur * 2] = true;
			depth[cur * 2] = depth[cur] + 1;
		}
	}
}

int main() {
	cin >> N >> K;
	bfs(N);
	cout << depth[K];
	return 0;
}
