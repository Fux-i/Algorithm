#include <iostream>

using namespace std;

void exec() {
	int n;
	string target;
	cin >> n >> target;
	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (target[i] == '0') {
			if (num == 1) {
				cout << "NO" << endl;
				return;
			}
			num = 0;
		} else {
			++num;
		}
	}
	if (num == 1) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		exec();
	}
}