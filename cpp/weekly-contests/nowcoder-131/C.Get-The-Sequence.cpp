#include <iostream>
#include <vector>

using namespace std;

void exec() {
	int n1, n2;
	cin >> n1 >> n2;

	vector<int> v1{};
	v1.reserve(n1);
	vector<int> v2{};
	v2.reserve(n2);
	for (int i = 0; i < n1; ++i) {
		int val;
		cin >> val;
		v1.push_back(val);
	}
	for (int i = 0; i < n2; ++i) {
		int val;
		cin >> val;
		v2.push_back(val);
	}

	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (v1[i] >= v2[j]) {
			++i; ++j;
		} else {
			++i;
		}
	}
	if (j == n2) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		exec();
	}
}