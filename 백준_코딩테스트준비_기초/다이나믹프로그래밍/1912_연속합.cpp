#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int n;
long long answer;
long long A[MAX];
long long d[MAX];

void dp() {
	d[1] = A[1];
	answer = A[1];
	for (int i = 2; i <= n; ++i) {
		d[i] = max(d[i - 1] + A[i], A[i]);
		answer = max(answer, d[i]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	dp();
	cout << answer << '\n';
	return 0;
}
