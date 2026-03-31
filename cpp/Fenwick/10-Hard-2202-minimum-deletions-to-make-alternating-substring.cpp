#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
	vector<T> tree;
public:
	fenwick(int n) : tree(n + 1) {}
	void update(int i, T val) {
		for (; i < tree.size(); i += i & -i) tree[i] += val;
	}
	T pre(int i) const {
		T res = 0;
		for (; i > 0; i &= i - 1) res += tree[i];
		return res;
	}
	T query(int l, int r) const {
		if (r < l) return 0;
		return pre(r) - pre(l - 1);
	}
};

class Solution {
public:
	vector<int> minDeletions(string s, vector<vector<int> > &queries) {
		int n = s.size();
		fenwick<int> t(n - 1);
		for (int i = 1; i < n; i++)
			if (s[i - 1] == s[i]) t.update(i, 1);

		vector<int> ans;
		for (auto &q: queries) {
			if (q[0] == 2) {
				ans.push_back(t.query(q[1] + 1, q[2]));
				continue;
			}
			int i = q[1];
			if (i > 0) t.update(i, s[i - 1] != s[i] ? 1 : -1);
			if (i < n - 1) t.update(i + 1, s[i] != s[i + 1] ? 1 : -1);
			s[i] ^= 'A' ^ 'B'; // A 变成 B，B 变成 A
		}
		return ans;
	}
};
