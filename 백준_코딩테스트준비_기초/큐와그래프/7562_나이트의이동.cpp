#include <iostream>
#include <queue>
#include <utility>
#define MAX 300
using namespace std;

int chessBoard[MAX][MAX], T, L, cur_x, cur_y, dest_x, dest_y, next_x, next_y;
bool visited[MAX][MAX];
int path_count[MAX][MAX];
int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 };
queue<pair<int, int>> q;

void bfs() {
	pair<int, int> p;
	p = make_pair(cur_x, cur_y);
	q.push(p);
	visited[cur_x][cur_y] = 1; // 방문 처리
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (p.first == dest_x && p.second == dest_y) break; // 도착
		for (int i = 0; i < 8; i++) {
			next_x = p.first + dx[i];
			next_y = p.second + dy[i];
			if (next_x < 0 || next_y < 0 || next_x >= L || next_y >= L) continue; // 범위 체크
				if (visited[next_x][next_y] == 0) { // 방문한적이 없으면
					visited[next_x][next_y] = 1;
					path_count[next_x][next_y] = path_count[p.first][p.second] + 1; // 이동 횟수 +1
					q.push(make_pair(next_x, next_y));
				}
		}

	}
}

void init() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			chessBoard[i][j] = 0;
			visited[i][j] = 0;
			path_count[i][j] = 0;
		}
	}
	while (!q.empty())
		q.pop();
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> L >> cur_x >> cur_y >> dest_x >> dest_y;
		bfs();
		cout << path_count[dest_x][dest_y] << '\n';
		init();
	}
	return 0;
}
