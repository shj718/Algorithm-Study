#include <iostream>
#define NUM 1000000000
using namespace std;

int N;
long long d[101][10];

void dp() {
	for (int i = 1; i <= 9; ++i) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0)
				d[i][j] = d[i - 1][j + 1];
			else if (j == 9)
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			d[i][j] = d[i][j] % NUM;
		}
	}
}

int main() {
	long long answer = 0;
	cin >> N;
	dp();
	for (int i = 0; i <= 9; ++i)
		answer += d[N][i];
	cout << answer % NUM << '\n';
	return 0;
}
