#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> adj[MAX];
int N, M, cnt;
int visited[MAX];

void BFS(int v) {
	queue<int> Queue;
	visited[v] = true;
	Queue.push(v);
	while (!Queue.empty()) {
		int front = Queue.front();
		Queue.pop();
		for (int i = 0; i < adj[front].size(); ++i) {
			int adjacent = adj[front][i];
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				Queue.push(adjacent);
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	int u, v;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
	return 0;
}
