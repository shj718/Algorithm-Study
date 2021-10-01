#include <iostream>
#include <algorithm>
using namespace std;

int N;
int d[1001]; //d[x]는 x개의 카드를 구매하기 위해 지불해야 하는 금액의 최댓값
int price[10001]; //price[y]는 카드가 y개 포함된 카드팩의 가격

void dp() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] = max(d[i], d[i - j] + price[j]);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> price[i];
	}
	dp();
	cout << d[N] << '\n';
	return 0;
}
