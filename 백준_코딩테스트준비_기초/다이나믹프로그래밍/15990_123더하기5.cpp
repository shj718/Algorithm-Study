#include <iostream>
#define MAX 100001
#define NUM 1000000009
using namespace std;

int T, n;
long long d[MAX][4];

void dp() {
	d[1][1] = 1;
	d[2][2] = 1;
	for (int i = 1; i <= 3; ++i)
		d[3][i] = 1;
	for (int i = 4; i <= n; ++i) {
		d[i][1] = d[i - 1][2] + d[i - 1][3];
		d[i][2] = d[i - 2][1] + d[i - 2][3];
		d[i][3] = d[i - 3][1] + d[i - 3][2];
		for (int j = 1; j <= 3; ++j)
			d[i][j] = d[i][j] % NUM;
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n;
		dp();
		cout << (d[n][1] + d[n][2] + d[n][3]) % NUM << '\n';
	}
	return 0;
}
