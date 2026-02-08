#include <iostream>

using namespace std;

void exec(int n) {
	int x[4], y[4], idx = 0;
	float avg_x = 0, avg_y = 0;
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < n; ++j) {
			if (line[j] == '*') {
				x[idx] = i;
				avg_x += i;
				y[idx] = j;
				avg_y += j;
				++idx;
			}
		}
	}
	bool match = false;
	avg_x /= 4;
	avg_y /= 4;
	for (int i = 0; i < n; ++i) {
		if (avg_x == x[i] || avg_y == y[i]) {
			match = true;
			break;
		}
	}
	cout << (match ? 'T' : 'L') << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		exec(n);
	}
}
