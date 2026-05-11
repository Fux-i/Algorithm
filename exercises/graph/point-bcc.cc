// https://www.luogu.com.cn/problem/P8435
// tag -point-bcc -biconnected-component -tarjan

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e5 + 2, maxm = 4e6 + 2;
int n, m, to[maxm], nxt[maxm], hd[maxn], idx = 2;
int bcc_cnt = 0, dfn[maxn], dfn_cnt = 0, low[maxn], stk[maxn], tp = 0;
vector<int> vs[maxn];
bool vis[maxn];

void add(int u, int v) {
	to[idx] = v;
	nxt[idx] = hd[u];
	hd[u] = idx++;
}
void uadd(int u, int v) {
	add(u, v), add(v, u);
}

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++dfn_cnt, stk[tp++] = u;
	int son = 0;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (dfn[v] == 0) {
			++son;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++bcc_cnt;
				int x;
				do {
					x = stk[--tp];
					vs[bcc_cnt].push_back(x);
				} while (x != v);
				vs[bcc_cnt].push_back(u);
			}
		} else if (v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (son == 0 && fa == 0) vs[++bcc_cnt].push_back(u);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		uadd(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (dfn[i] == 0)
			tarjan(i, 0);

	cout << bcc_cnt << '\n';
	for (int i = 1; i <= bcc_cnt; ++i) {
		auto &v = vs[i];
		cout << v.size() << ' ';
		for (int j = v.size() - 1; j >= 0; --j) {
			cout << v[j] << " \n"[j == 0];
		}
	}
}

/*

6 5
1 3
2 4
1 2
4 6
2 3

*/