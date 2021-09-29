#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
int d[MAX];

void dp() {
	d[1] = 0;
	for (int i = 2; i <= N; ++i) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = min(d[i / 2] + 1, d[i]);
		if (i % 3 == 0)
			d[i] = min(d[i / 3] + 1, d[i]);
	}
}

int main() {
	cin >> N;
	dp();
	cout << d[N] << '\n';
	return 0;
}
