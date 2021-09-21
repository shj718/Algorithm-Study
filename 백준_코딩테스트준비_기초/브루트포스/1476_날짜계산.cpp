#include <iostream>
#define E 15
#define S 28
#define M 19
using namespace std;

int main() {
	int e, s, m;
	int x;
	int i = 0;
	cin >> e;
	cin >> s;
	cin >> m;

	while (1) {
		x = S * i + s;
		if ((x - 1) % M + 1 == m) {
			if ((x - 1) % E + 1 == e) {
				cout << x << endl;
				break;
			}
		}
		i++;
	}
	return 0;
}
