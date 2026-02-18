#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void exec() {
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, int> dp;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		int current = 1;
		if (dp.count(v[i] - 1))
			current = max(current, dp[v[i] - 1] + 1);
		if (dp.count(v[i] + 1))
			current = max(current, dp[v[i] + 1] + 1);

		dp[v[i]] = max(dp[v[i]], current);
		ans = max(ans, dp[v[i]]);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) exec();
}
