#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;
int d[MAX];

void dp() {
	for (int i = 1; i <= N; ++i) {
		d[i] = i;
		for (int j = 1; j * j <= i; ++j)
			d[i] = min(d[i], d[i - j * j] + 1);
	}
}

int main() {
	cin >> N;
	dp();
	cout << d[N] << '\n';
	return 0;
}
