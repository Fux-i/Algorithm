#include <bits/stdc++.h>
#define m ((r - l >> 1) + l)
using namespace std;

constexpr int maxn = 1e5 + 2, maxk = 2e5 + 2;
int n, k, ui, ans[maxn];

struct Node {
	int a, b, c;
	int cnt, res;
	strong_ordering operator<=>(const Node &other) const {
		if (auto cmp = a <=> other.a; cmp != 0) return cmp;
		if (auto cmp = b <=> other.b; cmp != 0) return cmp;
		return c <=> other.c;
	}
	bool operator==(const Node &other) const {
		return a == other.a && b == other.b && c == other.c;
	}
};

bool cmp_b(Node x, Node y) {
	if (x.b != y.b) return x.b < y.b;
	return x.c < y.c;
}

Node o[maxn], uo[maxn];

struct fenwick {
	int tree[maxk];
	int lowbit(int x) { return x & -x; }
	void add(int x, int cnt) {
		while (x <= k) {
			tree[x] += cnt;
			x += lowbit(x);
		}
	}
	int pre_sum(int x) {
		int res = 0;
		while (x) {
			res += tree[x];
			x -= lowbit(x);
		}
		return res;
	}
} f;

void CDQ(int l, int r) {
	if (l == r) return;
	CDQ(l, m), CDQ(m + 1, r);
	sort(uo + l, uo + m + 1, cmp_b);
	sort(uo + m + 1, uo + r + 1, cmp_b);
	int i = l, j = m + 1;
	while (j <= r) {
		while (i <= m && uo[i].b <= uo[j].b) {
			f.add(uo[i].c, uo[i].cnt);
			i++;
		}
		uo[j].res += f.pre_sum(uo[j].c);
		j++;
	}
	for (int k = l; k < i; ++k) f.add(uo[k].c, -uo[k].cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> o[i].a >> o[i].b >> o[i].c;
	sort(o + 1, o + n + 1);
	int t = 0;
	for (int i = 1; i <= n; ++i) {
		t++;
		if (o[i] != o[i + 1]) {
			ui++;
			uo[ui].a = o[i].a;
			uo[ui].b = o[i].b;
			uo[ui].c = o[i].c;
			uo[ui].cnt = t;
			t = 0;
		}
	}

	CDQ(1, ui);
	for (int i = 1; i <= ui; ++i) ans[uo[i].res + uo[i].cnt - 1] += uo[i].cnt;
	for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}

/*
10 3
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1


*/
