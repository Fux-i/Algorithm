#include <vector>
using namespace std;

class segtree {
	int n;
	vector<int> tree;

	void build(const vector<int> &v, int idx, int l, int r) {
		if (l == r) {
			tree[idx] = v[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(v, idx * 2 + 1, l, mid);
		build(v, idx * 2 + 2, mid + 1, r);
		tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
	}

	// find the minimal index in [pos, r] making tree[index] > value
	int query(int pos, int value, int idx, int l, int r) {
		if (tree[idx] <= value) return -1; // 整个区间最大值都不够
		if (l == r) return l;

		int mid = (l + r) >> 1;
		if (pos <= mid) {
			int res = query(pos, value, idx * 2 + 1, l, mid);
			if (res != -1) return res;
		}
		return query(pos, value, idx * 2 + 2, mid + 1, r);
	}

public:
	segtree(vector<int> &init) : n(init.size()), tree(4 * n) {
		build(init, 0, 0, n - 1);
	}

	int query(int pos, int value) {
		if (pos >= n) return -1;
		return query(pos, value, 0, 0, n - 1);
	}
};

class Solution {
public:
	vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int> > &queries) {
		segtree t(heights);
		vector<int> ans;
		ans.reserve(queries.size());

		for (auto &q: queries) {
			int a = q[0], b = q[1];
			if (a > b) swap(a, b);

			if (a == b || heights[a] < heights[b]) ans.push_back(b);
			else ans.push_back(t.query(b + 1, heights[a]));
		}
		return ans;
	}
};
