// https://www.luogu.com.cn/problem/U582665
// tag -cut-edge(no dup) -tarjan

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e5 + 2, maxm = 4e6 + 2;
int n, m, to[maxm], nxt[maxm], hd[maxn], cnt = 0;
int dfn_cnt = 0, dfn[maxn], low[maxn];

unordered_set<int> s{};
priority_queue<int, vector<int>, greater<> > q{};

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++dfn_cnt;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (dfn[v] == 0) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				s.emplace((i + 1) / 2);
			}
		} else if (v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		to[++cnt] = v; nxt[cnt] = hd[u]; hd[u] = cnt;
		to[++cnt] = u; nxt[cnt] = hd[v]; hd[v] = cnt;
	}
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0)
			tarjan(i, i);
	}
	for (int i : s) q.emplace(i);
	cout << q.size() << '\n';
	while (!q.empty()) {
		cout << q.top();
		q.pop();
		if (!q.empty()) cout << ' ';
	}
}
