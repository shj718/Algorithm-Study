#include <iostream>
#include<algorithm>
using namespace std;

// 처음에 틀렸던 이유: i=1(앞)부터 순차적으로 탐색함 -> 역순으로 해결.

int N;
int profit[21]; // i+T[i] 의 최댓값이 20 이므로.
int T[16];
int P[16];

void solve() {
	for (int i = N; i >= 1; --i) {
		if (i + T[i] > N + 1) // ( i번째날 + 상담기간 )이 퇴사날 이후인 경우
			profit[i] = profit[i + 1];
		else
			profit[i] = max(profit[i + T[i]] + P[i], profit[i + 1]); //그날 상담을 하고 상담기간이 끝난후 바로 그 다음날 상담을 하는 경우 VS 그날 상담 X
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> P[i];
	}
	solve();
	cout << profit[1] << '\n';
  return 0;
}
