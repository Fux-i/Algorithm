// https://www.luogu.com.cn/problem/P1552
// tag: -mergeable-heap

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int maxn = 1e5 + 2;
int n, m, b[maxn], c[maxn], l[maxn], lc[maxn], rc[maxn], dis[maxn], siz[maxn],
    rt[maxn];
ll ans = 0, sum[maxn];

int merge(int x, int y) {
  if (!x || !y)
    return x | y;
  if (c[x] < c[y])
    swap(x, y);
  rc[x] = merge(rc[x], y);
  if (dis[lc[x]] < dis[rc[x]])
    swap(lc[x], rc[x]);
  dis[x] = dis[rc[x]] + 1;
  return x;
}

int del(int x) { return merge(lc[x], rc[x]); }

void calc(int u) {
  while (sum[u] > m) {
    sum[u] -= c[rt[u]], siz[u]--;
    rt[u] = del(rt[u]);
  }
  ans = max(ans, ll(siz[u]) * l[u]);
  int o = b[u];
  if (o == 0)
    return;
  rt[o] = merge(rt[o], rt[u]);
  sum[o] += sum[u], siz[o] += siz[u];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  dis[0] = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i] >> c[i] >> l[i];
    rt[i] = i;
    siz[i] = 1, sum[i] = c[i];
  }
  for (int i = n; i > 0; --i)
    calc(i);
  cout << ans << '\n';
}
