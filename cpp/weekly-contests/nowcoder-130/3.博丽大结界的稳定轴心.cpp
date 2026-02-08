#include <iostream>
#include <vector>

using namespace std;

void exec(int n) {
}

int main() {
	int n;
	cin >> n;
	int t = n - 1;
	vector<int> set(n + 1, 0);
	int num_3 = 0;
	while (t--) {
		int u, v;
		cin >> u >> v;
		if (++set[u] == 3) ++num_3;
		if (++set[v] == 3) ++num_3;
		if (set[u] > 3 || set[v] > 3) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << n - num_3 << endl;
}