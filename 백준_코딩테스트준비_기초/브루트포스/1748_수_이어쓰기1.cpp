#include <iostream>
#include <cmath>
using namespace std;

int get_digit(int N) {
	int i = 10;
	while (1) {
		if (N % i == N) {
			break;
		}
		else
			i *= 10;
	}
	return log10(i);
}

long long calculate(int N, int digit) {
	long long sum = 0;
	for (int i = 1; i < digit; ++i) {
		sum += i * 9 * pow(10, i - 1);
	}
	sum += digit * (N - pow(10, digit - 1) + 1);
	return sum;
}

int main() {
	int N;
	int digit;
	cin >> N;
	digit = get_digit(N);
	cout << calculate(N, digit) << endl;
	return 0;
}
