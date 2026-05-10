// https://www.luogu.com.cn/problem/B3609
// tag -scc -tarjan

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e4 + 2, maxm = 1e5 + 2;
int n, m, to[maxm], nxt[maxm], hd[maxn];
int scc[maxn], scc_cnt = 0, dfn[maxn], dfn_cnt = 0, low[maxn], stk[maxn], tp = 0;
priority_queue<int, vector<int>, greater<> > qs[maxn];
bool in_stk[maxn], vis[maxn];

void tarjan(int u) {
	dfn[u] = low[u] = ++dfn_cnt, stk[tp++] = u, in_stk[u] = true;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (in_stk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++scc_cnt;
		int x;
		do {
			x = stk[--tp];
			scc[x] = scc_cnt;
			in_stk[x] = false;
			qs[scc_cnt].emplace(x);
		} while (x != u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		to[i] = v;
		nxt[i] = hd[u];
		hd[u] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0)
			tarjan(i);
	}
	cout << scc_cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (vis[scc[i]])
			continue;
		vis[scc[i]] = true;
		auto &q = qs[scc[i]];
		cout << q.top();
		q.pop();
		while (!q.empty()) {
			cout << ' ' << q.top();
			q.pop();
		}
		cout << '\n';
	}
}
