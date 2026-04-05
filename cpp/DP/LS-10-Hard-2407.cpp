#include <algorithm>
#include <vector>
#define m (l + r >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)

using namespace std;

class Solution {
	vector<int> tree;

	void update(int i, int l, int r, int x, int len) {
		if (l == r) {
			tree[i] = len;
			return;
		}
		if (x <= m) update(lc, l, m, x, len);
		else update(rc, m + 1, r, x, len);
		tree[i] = max(tree[lc], tree[rc]);
	}

	int query(int i, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return tree[i];
		int max_val = 0;
		if (ql <= m) max_val = query(lc, l, m, ql, qr);
		if (qr > m) max_val = max(max_val, query(rc, m + 1, r, ql, qr));
		return max_val;
	}
public:
	int lengthOfLIS(vector<int> &nums, int k) {
		int max_val = *ranges::max_element(nums);
		int n = max_val * 4;
		int max_len = 1;
		tree.assign(n + 1, 0);
		for (int num : nums) {
			if (num == 1) {
				update(1, 1, n, 1, 1);
				continue;
			}
			int len = 1 + query(1, 1, max_val, max(num - k, 1), num - 1);
			max_len = max(max_len, len);
			update(1, 1, max_val, num, len);
		}
		return max_len;
	}
};

int main() {
	Solution s{};
	vector<int> v{4,2,1,4,3,4,5,8,15};
	s.lengthOfLIS(v,3);
}