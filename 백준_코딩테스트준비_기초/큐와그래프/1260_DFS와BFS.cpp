#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> adj[MAX];
int N, M, V;
int visited[MAX];

void DFS(int v) {
	if (visited[v])
		return;
	visited[v] = true;
	cout << v << ' ';
	for (int i = 0; i < adj[v].size(); ++i) {
		int adjacent = adj[v][i];
		DFS(adjacent);
	}
}

void BFS(int v) {
	queue<int> Queue;
	visited[v] = true;
	Queue.push(v);
	while (!Queue.empty()) {
		int front = Queue.front();
		Queue.pop();
		cout << front << ' ';
		for (int i = 0; i < adj[front].size(); ++i) {
			int adjacent = adj[front][i];
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				Queue.push(adjacent);
			}
		}
	}
}

int main() {
	int a, b;
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
		sort(adj[i].begin(), adj[i].end());
	DFS(V);
	cout << '\n';
	for (int i = 1; i <= N; ++i)
		visited[i] = false;
	BFS(V);
	return 0;
}
