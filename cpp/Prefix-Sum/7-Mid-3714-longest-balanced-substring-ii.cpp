#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
	int longestBalanced(string s) {
		int n = s.size();
		int ans = 0;

		for (int i = 0; i < n;) {
			int start = i;
			for (i++; i < n && s[i] == s[i - 1]; i++);
			ans = max(ans, i - start);
		}

		auto f = [&](char x, char y) -> void {
			for (int i = 0; i < n; i++) {
				unordered_map<int, int> pos = {{0, i - 1}};
				int d = 0;
				for (; i < n && (s[i] == x || s[i] == y); i++) {
					d += s[i] == x ? 1 : -1;
					if (pos.contains(d)) ans = max(ans, i - pos[d]);
					else pos[d] = i;
				}
			}
		};
		f('a', 'b');
		f('a', 'c');
		f('b', 'c');

		unordered_map<long long, int> pos = {{1LL * n << 32 | n, -1}};
		int cnt[3]{};
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			long long p = 1LL * (cnt[0] - cnt[1] + n) << 32 | (cnt[1] - cnt[2] + n);
			if (pos.contains(p)) ans = max(ans, i - pos[p]);
			else pos[p] = i;
		}
		return ans;
	}
};
