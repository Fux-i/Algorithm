#include <vector>
using namespace std;

class BookMyShow {
	int n, m;
	vector<int> mn;
	vector<long long> sum;

	void update(int o, int l, int r, int i, int val) {
		if (l == r) {
			mn[o] += val;
			sum[o] += val;
			return;
		}
		int mid = (l + r) / 2;
		if (i <= mid) update(o * 2, l, mid, i, val);
		else update(o * 2 + 1, mid + 1, r, i, val);
		mn[o] = min(mn[o * 2], mn[o * 2 + 1]);
		sum[o] = sum[o * 2] + sum[o * 2 + 1];
	}

	long long querySum(int o, int l, int r, int L, int R) {
		if (L <= l && r <= R) return sum[o];
		long long res = 0;
		int mid = (l + r) / 2;
		if (L <= mid) res = querySum(o * 2, l, mid, L, R);
		if (R > mid) res += querySum(o * 2 + 1, mid + 1, r, L, R);
		return res;
	}

	int findFirst(int o, int l, int r, int R, int val) {
		if (mn[o] > val) return -1;
		if (l == r) return l;
		int mid = (l + r) / 2;
		if (mn[o * 2] <= val) return findFirst(o * 2, l, mid, R, val);
		if (R > mid) return findFirst(o * 2 + 1, mid + 1, r, R, val);
		return -1;
	}

public:
	BookMyShow(int n, int m) : n(n), m(m), mn(4 << __lg(n)), sum(4 << __lg(n)) { }

	vector<int> gather(int k, int maxRow) {
		int r = findFirst(1, 0, n - 1, maxRow, m - k);
		if (r < 0) return {};
		int c = querySum(1, 0, n - 1, r, r);
		update(1, 0, n - 1, r, k);
		return {r, c};
	}

	bool scatter(int k, int maxRow) {
		long long s = querySum(1, 0, n - 1, 0, maxRow);
		if (s > (long long) m * (maxRow + 1) - k) return false;
		int i = findFirst(1, 0, n - 1, maxRow, m - 1);
		while (k) {
			int left = min(m - (int) querySum(1, 0, n - 1, i, i), k);
			update(1, 0, n - 1, i, left);
			k -= left;
			i++;
		}
		return true;
	}
};
