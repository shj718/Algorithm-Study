#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int solve(int numOfYears, int M, int N, int x, int y) {
	int a = 0;
	int i = 0;
	while(a <= numOfYears) {
		a = M * i + x;
		if ((a - 1) % N + 1 == y)
			return a;
		i++;
	}
	return -1;
}

int main() {
	int T, M, N, x, y;
	int numOfYears;
	cin >> T;
	int* answer = new int[T];
	for (int i = 0; i < T; ++i) {
		cin >> M >> N >> x >> y;
		numOfYears = M * N / gcd(M, N);
		answer[i] = solve(numOfYears, M, N, x, y);
	}
	for (int i = 0; i < T; ++i) {
		cout << answer[i] << '\n';
	}
	delete[] answer;
	return 0;
}
