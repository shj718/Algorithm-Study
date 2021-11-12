#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 25
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int N;
vector<int> houseNum;
int houseCount;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inRange(int i, int j) {
	if ((i >= 0 && i < N) && (j >= 0 && j < N)) return true;
	else return false;
}

void DFS(int i, int j) { /* 어떤 집에 대해 위, 아래, 왼쪽, 오른쪽을 이웃이라고 가정하고 DFS */
	for (int k = 0; k < 4; ++k) {
		int next_i = i + dx[k];
		int next_j = j + dy[k];
		if (!inRange(next_i, next_j)) continue;
		if (map[next_i][next_j] == 1 && visited[next_i][next_j] == false) {
			visited[next_i][next_j] = true;
			houseCount++;
			DFS(next_i, next_j);
		}
	}
}

void solve() {
	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				visited[i][j] = true;
				houseCount++;
				DFS(i, j);
				houseNum.push_back(houseCount);
				houseCount = 0;
			}
		}
	}
}

int main() {
	int i, j; // (5≤N≤25)
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j)
			scanf("%1d", &map[i][j]);
	}
	solve();
	cout << houseNum.size() << '\n';
	sort(houseNum.begin(),houseNum.end());
	for (i = 0; i < houseNum.size(); ++i)
		cout << houseNum[i] << '\n';
}
