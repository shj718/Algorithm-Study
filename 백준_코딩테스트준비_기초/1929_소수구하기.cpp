#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	bool* array_prime = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		array_prime[i] = true;
	}
	for (int i = 2; i * i <= n; ++i) {
		if (array_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                if(array_prime[j])
                    array_prime[j] = false;
            }
        }
	}
	if (m == 1) {
		m++;
	}
	for (int i = m; i <= n; ++i) {
		if (array_prime[i])
			cout << i << '\n';
	}
	delete[] array_prime;
	return 0;
}
