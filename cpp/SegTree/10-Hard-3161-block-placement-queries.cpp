#include <bits/stdc++.h>
#define m ((l + r) >> 1)
#define lc (idx * 2 + 1)
#define rc (idx * 2 + 2)

using namespace std;

class segtree {
	int n;
	vector<int> tree;

	void update(int idx, int l, int r, int i, int val) {
		if (l == r) {
			tree[idx] = val;
			return;
		}
		if (i <= m) update(lc, l, m, i, val);
		else update(rc, m + 1, r, i, val);
		tree[idx] = max(tree[lc], tree[rc]);
	}

	int query(int idx, int l, int r, int qr) {
		if (r <= qr) return tree[idx];
		if (qr <= m) return query(lc, l, m, qr);
		return max(tree[lc], query(rc, m + 1, r, qr));
	}

public:
	segtree(int n_) : n(n_), tree(n * 4) {
	}

	void update(int i, int val) {
		update(0, 0, n - 1, i, val);
	}

	int query(int i) {
		return query(0, 0, n - 1, i);
	}
};

class Solution {
public:
	vector<bool> getResults(vector<vector<int> > &queries) {
		int margin = 0;
		for (auto &q: queries)
			margin = max(margin, q[1]);
		margin++;

		set<int> barriers{0, margin};
		segtree t{margin};

		vector<bool> ans;
		ans.reserve(queries.size());
		for (auto &q: queries) {
			int x = q[1];
			auto it = barriers.lower_bound(x);
			int prv = *prev(it);
			if (q[0] == 1) {
				int nxt = *it;
				barriers.insert(x);
				t.update(x, x - prv);
				t.update(nxt, nxt - x);
			} else {
				int len = max(t.query(prv), x - prv);
				ans.push_back(len >= q[2]);
			}
		}
		return ans;
	}
};
