// https://www.luogu.com.cn/problem/P3388
// tag -cut-point -tarjan

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e4 + 2, maxm = 2e5 + 2;
int n, m, to[maxm], nxt[maxm], hd[maxn], cnt = 0;
int dfn_cnt = 0, dfn[maxn], low[maxn];
bool flag[maxn];
priority_queue<int, vector<int>, greater<> > q{};

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++dfn_cnt;
	int son = 0;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (dfn[v] == 0) {
			son++;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (u != fa && low[v] >= dfn[u] && !flag[u]) {
				flag[u] = true;
				q.emplace(u);
			}
		} else if (v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (u == fa && son >= 2 && !flag[u]) {
		flag[u] = true;
		q.emplace(u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		to[++cnt] = v;
		nxt[cnt] = hd[u];
		hd[u] = cnt;
		to[++cnt] = u;
		nxt[cnt] = hd[v];
		hd[v] = cnt;
	}
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0)
			tarjan(i, i);
	}
	cout << q.size() << '\n';
	while (!q.empty()) {
		cout << q.top();
		q.pop();
		if (!q.empty()) cout << ' ';
	}
}
