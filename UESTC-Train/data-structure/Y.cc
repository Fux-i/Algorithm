#include <bits/stdc++.h>
#define m ((r - l >> 1) + l)
#define lc (idx << 1)
#define rc (idx << 1 | 1)

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

constexpr int maxn = 500005;
int n, q, to[maxn << 1], nxt[maxn << 1], head[maxn], siz[maxn], fa[maxn], son[maxn], top[maxn], dfn[maxn];
int cnt = 0, ecnt = 0;

void dfs1(int u, int f) {
	fa[u] = f, siz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	dfn[u] = ++cnt;
	if (son[u] == 0) return;
	dfs2(son[u], t);
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa[u]) continue;
		if (v != son[u]) dfs2(v, v);
	}
}

class segtree {
	vector<char> tree, todo;

	void push(int idx) {
		if (todo[idx] == 2) return;
		tree[lc] = tree[rc] = todo[lc] = todo[rc] = todo[idx];
		todo[idx] = 2;
	}

	char query(int idx, int l, int r, int t) {
		if (l == r) return tree[idx];
		push(idx);
		if (t <= m) return query(lc, l, m, t);
		return query(rc, m + 1, r, t);
	}

	void update(int idx, int l, int r, int ql, int qr, char v) {
		if (ql <= l && r <= qr) {
			tree[idx] = v;
			todo[idx] = v;
			return;
		}
		push(idx);
		if (ql <= m) update(lc, l, m, ql, qr, v);
		if (qr > m) update(rc, m + 1, r, ql, qr, v);
	}

public:
	segtree() : tree(4 * n), todo(4 * n, 2) {
	}

	char query(int t) {
		return query(1, 1, n, dfn[t]);
	}

	void water(int u) {
		update(1, 1, n, dfn[u], dfn[u] + siz[u] - 1, 1);
	}

	void drain(int u) {
		while (top[u] != 1) {
			update(1, 1, n, dfn[top[u]], dfn[u], 0);
			u = fa[top[u]];
		}
		update(1, 1, n, dfn[1], dfn[u], 0);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		to[++ecnt] = v;
		nxt[ecnt] = head[u];
		head[u] = ecnt;
		to[++ecnt] = u;
		nxt[ecnt] = head[v];
		head[v] = ecnt;
	}
	dfs1(1, 0);
	dfs2(1, 1);
	segtree st{};

	cin >> q;
	vector<char> ans{};
	for (int i = 0; i < q; ++i) {
		int type, u;
		cin >> type >> u;
		if (type == 1) st.water(u);
		else if (type == 2) st.drain(u);
		else ans.push_back(st.query(u));
	}
	for (auto a: ans) cout << +a << '\n';
}

/*


*/
