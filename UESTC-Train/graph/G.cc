#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 2, maxm = 2e5 + 2;
int to[maxm], nxt[maxm], hd[maxn], idx = 2;
int dfn[maxn], dfn_cnt = 0, low[maxn];
int n, m, cutp_cnt = 0, pbcc_cnt = 0, cute_cnt = 0, ebcc_cnt = 0;
bool cut[maxn];

void tarjan(int u, int e) {
	dfn[u] = low[u] = ++dfn_cnt;
	int son = 0;
	for (int i = hd[u]; i; i = nxt[i]) {
		if ((e ^ i) == 1) continue;
		int v = to[i];
		if (dfn[v] == 0) {
			++son;
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) cute_cnt++;
			if (low[v] >= dfn[u]) pbcc_cnt++;
			if (e != 0 && low[v] >= dfn[u] && !cut[u]) {
				cut[u] = true;
				cutp_cnt++;
			}
		} else low[u] = min(low[u], dfn[v]);
	}
	if (e == 0 && son == 0) pbcc_cnt++;
	if (e == 0 && son > 1) cutp_cnt++;
	if (dfn[u] == low[u]) ebcc_cnt++;
}

void add(int u, int v) {
	to[idx] = v;
	nxt[idx] = hd[u];
	hd[u] = idx++;
}
void uadd(int u, int v) {
	add(u, v), add(v, u);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		uadd(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (dfn[i] == 0) tarjan(i, 0);

	printf("%d %d %d %d", cutp_cnt, pbcc_cnt, cute_cnt, ebcc_cnt);
}

/*

10 8
1 2
1 3
3 4
3 5
4 5
2 6
2 7
6 7

*/
