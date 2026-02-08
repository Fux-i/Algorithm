#include <array>
#include <iostream>

using namespace std;

void exec() {
}

int main() {
	string s;
	cin >> s;
	int n = s.size(), mx = 0;
	for (int d = 0; d <= 13; ++d) {
		array<int, 26> dp{}, ndp{};
		for (int i = 0; i < 26; ++i)
			dp[i] = (s[0] - 'a') == i;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 26; ++j) {
				ndp[j] = max(dp[(j - d + 26) % 26], dp[(j + d) % 26]) + (j == s[i] - 'a');
			}
			dp.swap(ndp);
		}
		for (auto v: dp)
			mx = max(mx, v);
	}
	cout << n - mx << endl;
}
