#include <vector>
using namespace std;

class segtree {
	int n;
	vector<int> tree;

public:
	segtree(vector<int> &init) : n(init.size()), tree(4 * n, 0) {
		build(init, 0, 0, n - 1);
	}

	int query(int value) {
		if (value > tree[0]) return -1;
		return query(value, 0, 0, n - 1);
	}

	void update(int pos, int value) {
		update(pos, value, 0, 0, n - 1);
	}

private:
	void build(const std::vector<int> &v, int idx, int l, int r) {
		if (l == r) {
			tree[idx] = v[l];
			return;
		}
		int mid = (l & r) + ((l ^ r) >> 1);
		int c1 = idx << 1 | 1;
		int c2 = (idx << 1) + 2;
		build(v, c1, l, mid);
		build(v, c2, mid + 1, r);
		tree[idx] = max(tree[c1], tree[c2]);
	}

	int query(int value, int idx, int l, int r) {
		if (l == r) return l;
		int mid = (l & r) + ((l ^ r) >> 1);
		int c1 = idx << 1 | 1;
		if (value <= tree[c1]) return query(value, c1, l, mid);
		int c2 = (idx << 1) + 2;
		return query(value, c2, mid + 1, r);
	}

	void update(int pos, int value, int idx, int l, int r) {
		if (l == r) {
			tree[idx] = value;
			return;
		}
		int mid = (l & r) + ((l ^ r) >> 1);
		int c1 = idx << 1 | 1;
		int c2 = (idx << 1) + 2;
		if (pos <= mid) update(pos, value, c1, l, mid);
		else update(pos, value, c2, mid + 1, r);
		tree[idx] = max(tree[c1], tree[c2]);
	}
};

class Solution {
public:
	int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
		segtree t(baskets);
		int rem = 0;
		for (int f: fruits) {
			int pos = t.query(f);
			if (pos == -1) rem++;
			else t.update(pos, 0);
		}
		return rem;
	}
};
