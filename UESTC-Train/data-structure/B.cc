#include<bits/stdc++.h>

#define ll long long
using namespace std;

constexpr int maxn = 1e5 + 5;
ll color_sum, ans[maxn];
int to[maxn], nxt[maxn], head[maxn], color[maxn], cnt[maxn], son[maxn], siz[maxn], n, max_cnt;

void dfs1(int node) {
	int max_size = 0;
	siz[node] = 1;
	for (int i = head[node]; i; i = nxt[i]) {
		dfs1(to[i]);
		int child_size = siz[to[i]];
		siz[node] += child_size;
		if (child_size > max_size) {
			max_size = child_size;
			son[node] = to[i];
		}
	}
}

void add(int node, int val, int h_son = 0) {
	int new_cnt = cnt[color[node]] + val;
	cnt[color[node]] = new_cnt;
	if (new_cnt > max_cnt) {
		max_cnt = new_cnt;
		color_sum = color[node];
	} else if (new_cnt == max_cnt) {
		color_sum += color[node];
	}
	for (int i = head[node]; i; i = nxt[i]) {
		if (to[i] == h_son) continue;
		add(to[i], val);
	}
}

void dfs2(int node, bool clear) {
	int h_son = son[node];
	for (int i = head[node]; i; i = nxt[i]) {
		if (to[i] == h_son) continue;
		dfs2(to[i], true);
	}
	if (h_son) {
		dfs2(h_son, false);
	}
	add(node, 1, h_son);
	ans[node] = color_sum;
	if (clear) {
		add(node, -1);
		color_sum = 0;
		max_cnt = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		to[i] = v;
		nxt[i] = head[u];
		head[u] = i;
	}
	dfs1(1);
	dfs2(1, true);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
	}
}

/*
15
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3
1 2
1 3
1 4
1 14
1 15
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13


6 5 4 3 2 3 3 1 1 3 2 2 1 2 3

*/