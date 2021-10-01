#include <iostream>
#define MAX 91
using namespace std;

int N;
long long d[MAX][2];

void dp() {
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
}

int main() {
	cin >> N;
	dp();
	cout << d[N][0] + d[N][1] << '\n';
	return 0;
}
