#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	n *= m;
	map<int, int> h{};
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t > 0) ++h[t];
	}
	int count = 0, coin = 0;
	for (auto &[v, c] : h) {
		int add = c / 2;
		count += add;
		int x = v + 1;
		if (x >= k) coin += add;
		if (add > 1) {
			h[x] += add;
		} else if (h.contains(x)) {
			h[x] += add;
		}
	}
	cout << count << ' ' << coin << endl;
}
