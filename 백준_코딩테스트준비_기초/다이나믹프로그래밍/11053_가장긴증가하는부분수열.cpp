#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int A[MAX];
int d[MAX];

void dp() {
	d[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			if (A[j] < A[i])
				d[i] = max(d[i], d[j] + 1);
		}
		if (d[i] == 0)
			d[i]++;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	dp();
	cout << *max_element(d, d + MAX) << '\n';
	return 0;
}
