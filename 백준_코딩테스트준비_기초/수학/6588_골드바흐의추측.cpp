#include <iostream>
#define MAX 1000000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n, a, b;
	bool check_prime[MAX + 1];
	for (int i = 2; i <= MAX; ++i) {
		check_prime[i] = true;
	}
	for (int i = 2; i * i <= MAX; ++i) {
		if (check_prime) {
			for (int j = i * i; j <= MAX; j += i) {
				if (check_prime[j])
					check_prime[j] = false;
			}
		}
	}
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		a = 3;
		b = n - 3;
		while (a <= b) {
			b = n - a;
			if (check_prime[a]) {
				if (check_prime[b = n - a]) {
					cout << n << " = " << a << " + " << b << '\n';
					break;
				}
				else
					a += 2;

			}
			else
				a += 2;
		}
		if (a > b)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}
