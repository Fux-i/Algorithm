// https://www.luogu.com.cn/problem/P1456
// tag: -mergeable-heap

#include <iostream>

using namespace std;

constexpr int maxn = 1e5 + 2;
int n, m, lc[maxn], rc[maxn], dis[maxn], fa[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

struct Node {
  int id, v;
} mo[maxn];

int merge(int x, int y) {
  if (!x || !y)
    return x + y;
  if (mo[x].v < mo[y].v)
    swap(x, y);
  rc[x] = merge(rc[x], y);
  if (dis[lc[x]] < dis[rc[x]])
    swap(lc[x], rc[x]);
  dis[x] = dis[rc[x]] + 1;
  return x;
}

int battle(int x) {
  int v2 = mo[x].v = mo[x].v / 2;
  if (v2 >= mo[lc[x]].v && v2 >= mo[rc[x]].v)
    return x;
  int l = lc[x], r = rc[x];
  int root = merge(l, r);
  lc[x] = rc[x] = 0; // avoid infinite loop
  return fa[x] = fa[lc[x]] = fa[rc[x]] = merge(root, x);
}

int main() {
  while (cin >> n) {
    dis[0] = -1;
    for (int i = 1; i <= n; ++i)
      fa[i] = lc[i] = rc[i] = dis[i] = 0;
    for (int i = 1; i <= n; ++i)
      fa[i] = i, mo[i].id = i, cin >> mo[i].v;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      x = find(x), y = find(y);
      if (x == y) {
        cout << "-1\n";
        continue;
      }
      x = battle(x), y = battle(y);
      fa[x] = fa[y] = merge(x, y);
      cout << mo[fa[x]].v << '\n';
    }
  }
}
