#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pi = pair<int, int>;

constexpr int maxn = 502, maxm = 10002;
int edge[maxm][2], pre[maxm][maxn], suf[maxm][maxn], dsu[maxn], siz[maxn];
int n, m, k;

int find(int *d, int x) {
	return d[x] == x ? x : d[x] = find(d, d[x]);
}

void unite(int x, int y) {
	x = find(dsu, x), y = find(dsu, y);
	if (x == y) return;
	if (siz[x] > siz[y]) swap(x, y);
	dsu[x] = y;
	siz[y] += siz[x];
}

int query(int l, int r) {
	auto pre_dsu = pre[l - 1], suf_dsu = suf[r + 1];
	memcpy(dsu, pre_dsu, maxn * sizeof(int));
	for (int i = 1; i <= n; ++i) {
		unite(i, find(suf_dsu, i));
	}
	unordered_set<int> set{};
	for (int i = 1; i <= n; ++i) {
		set.emplace(find(dsu, i));
	}
	return set.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		edge[i][0] = u, edge[i][1] = v;
	}
	iota(std::begin(dsu), std::end(dsu), 0);
	fill(std::begin(siz), std::end(siz), 1);
	memcpy(pre[0], dsu, maxn * sizeof(int));
	for (int i = 1; i <= m; ++i) {
		unite(edge[i][0], edge[i][1]);
		memcpy(pre[i], dsu, maxn * sizeof(int));
	}
	iota(std::begin(dsu), std::end(dsu), 0);
	fill(std::begin(siz), std::end(siz), 1);
	memcpy(suf[m + 1], dsu, maxn * sizeof(int));
	for (int i = m; i >= 1; --i) {
		unite(edge[i][0], edge[i][1]);
		memcpy(suf[i], dsu, maxn * sizeof(int));
	}

	cin >> k;
	for (int i = 0; i < k; ++i) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << '\n';
	}
}

/*


*/