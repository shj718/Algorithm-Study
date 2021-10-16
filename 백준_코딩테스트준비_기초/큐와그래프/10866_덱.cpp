#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

int N, X;
int deque[MAX];
int front = 0;
int rear = 0;
int deque_size = 0;
string s;

bool full() {
	if ((rear + 1) % MAX == front)
		return true;
	else
		return false;
}

bool empty() {
	if (front == rear)
		return true;
	else
		return false;
}

void solve() {
	cin >> s;
	if (s == "push_front") {
		if (full())
			return;
		cin >> X;
		deque[front] = X;
		front = (front - 1 + MAX) % MAX;
		deque_size++;
	}
	else if (s == "push_back") {
		if (full())
			return;
		cin >> X;
		rear = (rear + 1) % MAX;
		deque[rear] = X;
		deque_size++;
	}
	else if (s == "pop_front") {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		front = (front + 1) % MAX;
		cout << deque[front] << '\n';
		deque_size--;
	}
	else if (s == "pop_back") {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		cout << deque[rear] << '\n';
		rear = (rear - 1 + MAX) % MAX;
		deque_size--;
	}
	else if (s == "size") {
		cout << deque_size << '\n';
	}
	else if (s == "empty") {
		if (empty())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	else if (s == "front") {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		cout << deque[(front + 1) % MAX] << '\n';
	}
	else if (s == "back") {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		cout << deque[rear] << '\n';
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		solve();
	return 0;
}
