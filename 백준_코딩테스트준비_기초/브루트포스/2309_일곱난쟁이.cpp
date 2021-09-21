#include <iostream>
#include <algorithm>
using namespace std;

void solve(int sum, int* height) {
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - height[i] - height[j] == 100) {
				height[i] = -1;
				height[j] = -1;
				return;
			}
		}
	}
}

int main() {
	int height[9];
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> height[i];
		sum += height[i];
	}
	solve(sum, height);
	sort(height, height + 9);
	for (int i = 2; i < 9; ++i) {
		cout << height[i] << endl;
	}
	return 0;
}
