#include <iostream>
using namespace std;

int main() {
	long long x = 1;
	int n;
	int count = 1;
	while (cin >> n) {
		while (1) {
			if (x % n == 0) {
				break;
			}
            x = x % n;
			x = x * 10 + 1;
			count++;
		}
		cout << count << endl;
    x = 1;
    count = 1;
	}
	return 0;
}
