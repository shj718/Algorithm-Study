#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#define MAX 100
using namespace std;

int N, M, path_count;
int maze[MAX][MAX];
int path_cnt[MAX][MAX] = { 0, };
queue<pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inRange(int i, int j) {
	if ((i >= 0 && i < N) && (j >= 0 && j < M)) return true;
	else return false;
}

void BFS(int i, int j) {
	int cur_i, cur_j, next_i, next_j;
	pair <int, int> start = make_pair(i, j);
	pair <int, int> next;
	q.push(start);
	path_cnt[i][j]++;
	while (!q.empty()) {
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		if (cur_i == N - 1 && cur_j == M - 1) break;
		for (int k = 0; k < 4; ++k) {
			next_i = cur_i + dx[k];
			next_j = cur_j + dy[k];
			if (!inRange(next_i, next_j)) continue;
			if (path_cnt[next_i][next_j] == 0 && maze[next_i][next_j] == 1) {
				next = make_pair(next_i, next_j);
				q.push(next);
				path_cnt[next_i][next_j] = path_cnt[cur_i][cur_j] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);
	}
	BFS(0, 0);
	cout << path_cnt[N - 1][M - 1] << '\n';
}
