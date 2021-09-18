#include <iostream>
#include <algorithm>
using namespace std;

int check_max(char** arr, int N) {
	int max_candy = 0;
	for (int i = 0; i < N; ++i) {	//행 체크
		int same = 1;
		for (int j = 0; j < N - 1; ++j) {
			if (arr[i][j] == arr[i][j + 1]) {
				same++;
				max_candy = max(max_candy, same);
			}
			else
				same = 1;
		}
	}
	for (int j = 0; j < N; ++j) {	//열 체크
		int same = 1;
		for (int i = 0; i < N - 1; ++i) {
			if (arr[i][j] == arr[i+1][j]) {
				same++;
				max_candy = max(max_candy, same);
			}
			else
				same = 1;
		}
	}
	return max_candy;
}

int main() {
	int N;
	int answer = 0;
	cin >> N;
	char** arr = new char* [N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new char[N];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {	//가로 교환
		for (int j = 0; j < N - 1; ++j) {
			swap(arr[i][j], arr[i][j + 1]);
			answer = max(answer, check_max(arr, N));
			swap(arr[i][j], arr[i][j + 1]);
		}
	}
	for (int j = 0; j < N; ++j) {	//세로 교환
		for (int i = 0; i < N - 1; ++i) {
			swap(arr[i][j], arr[i + 1][j]);
			answer = max(answer, check_max(arr, N));
			swap(arr[i][j], arr[i + 1][j]);
		}
	}
	cout << answer << '\n';
	for (int i = 0; i < N; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
