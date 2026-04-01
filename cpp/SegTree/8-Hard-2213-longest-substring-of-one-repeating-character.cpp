#include <bits/stdc++.h>
#define m (l + r >> 1)
#define lc (idx * 2 + 1)
#define rc (idx * 2 + 2)

using namespace std;

class Solution {
	string s;
	vector<int> pre, suf, max;

	void maintain(int idx, int l, int r) {
		pre[idx] = pre[lc];
		suf[idx] = suf[rc];
		max[idx] = std::max(max[lc], max[rc]);
		if (s[m - 1] == s[m]) {
			if (suf[lc] == m - l + 1) pre[idx] += pre[rc];
			if (pre[rc] == r - m) suf[idx] += suf[lc];
			max[idx] = std::max(max[idx], suf[lc] + pre[rc]);
		}
	}

	void build(int idx, int l, int r) {
		if (l == r) {
			pre[idx] = suf[idx] = max[idx] = 1;
			return;
		}
		build(lc, l, m);
		build(rc, m + 1, r);
		maintain(idx, l, r);
	}

	void update(int idx, int l, int r, int i) {
		if (l == r) return;
		if (i <= m) update(lc, l, m, i);
		else update(rc, m + 1, r, i);
		maintain(idx, l, r);
	}

public:
	vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices) {
		this->s = s;
		int n = s.length(), len = queryIndices.size();
		pre.resize(n << 2);
		suf.resize(n << 2);
		max.resize(n << 2);
		build(1, 0, n - 1);
		vector<int> ans(len);
		for (int i = 0; i < len; ++i) {
			this->s[queryIndices[i]] = queryCharacters[i];
			update(1, 0, n - 1, queryIndices[i] + 1);
			ans[i] = max[1];
		}
		return ans;
	}
};
