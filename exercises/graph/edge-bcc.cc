// https://www.luogu.com.cn/problem/P8436
// tag -edge-bcc -biconnected-component -tarjan

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e5 + 2, maxm = 4e6 + 2;
int n, m, to[maxm], nxt[maxm], hd[maxn], idx = 2;
int scc[maxn], scc_cnt = 0, dfn[maxn], dfn_cnt = 0, low[maxn], stk[maxn], tp = 0;
vector<int> qs[maxn];
bool in_stk[maxn], vis[maxn];

void add(int u, int v) {
	to[idx] = v;
	nxt[idx] = hd[u];
	hd[u] = idx++;
}
void uadd(int u, int v) {
	add(u, v), add(v, u);
}

void tarjan(int u, int e) {
	dfn[u] = low[u] = ++dfn_cnt, stk[tp++] = u, in_stk[u] = true;
	for (int i = hd[u]; i; i = nxt[i]) {
		if ((i ^ e) == 1) continue;
		int v = to[i];
		if (dfn[v] == 0) {
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++scc_cnt;
		int x;
		do {
			x = stk[--tp];
			scc[x] = scc_cnt;
			in_stk[x] = false;
			qs[scc_cnt].push_back(x);
		} while (x != u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		uadd(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0)
			tarjan(i, 0);
	}
	cout << scc_cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (vis[scc[i]]) continue;
		vis[scc[i]] = true;
		auto &q = qs[scc[i]];
		cout << q.size() << ' ';
		for (int j = q.size() - 1; j >= 0; --j) {
			cout << q[j] << " \n"[j == 0];
		}
	}
}
