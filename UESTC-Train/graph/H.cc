#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

constexpr int maxn = 2e5 + 2;
int n, m, s, to[maxn], nxt[maxn], head[maxn];
int stk[maxn], top = 0, dfn[maxn], low[maxn], cnt = 0, scc[maxn], scc_cnt = 0, in[maxn];
bool in_stk[maxn];

void tarjan(int u) {
	dfn[u] = low[u] = ++cnt, stk[top++] = u, in_stk[u] = true;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
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
			x = stk[--top];
			scc[x] = scc_cnt;
			in_stk[x] = false;
		} while (x != u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		to[i] = v;
		nxt[i] = head[u];
		head[u] = i;
	}
	for (int u = 1; u <= n; ++u) {
		if (!dfn[u]) tarjan(u);
	}
	cnt = 0;
	for (int u = 1; u <= n; ++u) {
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			int uu = scc[u], vv = scc[v];
			if (uu == vv) continue;
			++in[vv];
		}
	}
	int in0_cnt = 0;
	for (int i = 1; i <= scc_cnt; ++i) {
		if (in[i] == 0) in0_cnt++;
	}
	if (in[scc[s]] == 0) in0_cnt--;
	cout << in0_cnt;
}

/*
9 9 1
1 2
1 3
2 3
1 4
4 5
5 6
6 4
7 8
8 9


5 4 5
1 2
2 3
3 4
4 1


*/
