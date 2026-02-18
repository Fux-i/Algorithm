#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void exec() {
	long long n;
	cin >> n;

	vector<long long> nums(n + 1);
	nums.reserve(n);
	for (long long i = 1; i <= n; ++i) {
		long long val;
		cin >> val;
		nums[i] = val;
	}

	vector<long long> nums_temp = nums, prefix(n), suffix(n + 2);
	for (long long i = 2; i < n; ++i) {
		long long sub = min(nums_temp[i], nums_temp[i - 1]);
		prefix[i] = prefix[i - 1] + sub;
		nums_temp[i] -= sub;
		nums_temp[i - 1] -= sub;
	}
	nums_temp = nums;
	for (long long i = n - 1; i > 1; --i) {
		long long sub = min(nums_temp[i], nums_temp[i + 1]);
		suffix[i] = suffix[i + 1] + sub;
		nums_temp[i] -= sub;
		nums_temp[i + 1] -= sub;
	}

	long long ans = 0;
	for (long long i = 1; i <= n; ++i) {
		ans = max(ans, prefix[i - 1] + nums[i] + suffix[i + 1]);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) exec();
}
