#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int N, X;
int queue[MAX];
int front = -1;
int rear = -1;
string s;

void solve() {
	cin >> s;
	if (s == "push") {
		cin >> X;
		queue[++rear] = X;
	}
	else if (s == "pop") {
		if (front == rear) {
			cout << -1 << '\n';
			return;
		}
		cout << queue[++front] << '\n';
		queue[front] = -1;
	}
	else if (s == "size") {
		cout << rear - front << '\n';
	}
	else if (s == "empty") {
		if (front == rear)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	else if (s == "front") {
		if (front == rear) {
			cout << -1 << '\n';
			return;
		}
		cout << queue[front + 1] << '\n';
	}
	else if (s == "back") {
		if (front == rear) {
			cout << -1 << '\n';
			return;
		}
		cout << queue[rear] << '\n';
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		solve();
	return 0;
}
