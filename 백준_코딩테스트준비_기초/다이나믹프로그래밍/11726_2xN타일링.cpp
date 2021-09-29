#include <iostream>
#define MAX 1001
using namespace std;

int n;
int d[MAX];

void dp() {
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; ++i) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] = d[i] % 10007;
	}
}

int main() {
	cin >> n;
	dp();
	cout << d[n] << '\n';
}
