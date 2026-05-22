// https://www.luogu.com.cn/problem/P3377
// tag: -mergeable-heap

#include <compare>
#include <iostream>

using namespace std;

constexpr int maxn = 1e5 + 2;
int n, m, lc[maxn], rc[maxn], dis[maxn], fa[maxn];
bool del[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

struct Node {
  int id, val;
  std::strong_ordering operator<=>(Node other) {
    if (val == other.val)
      return id <=> other.id;
    return val <=> other.val;
  }
} nodes[maxn];

int merge(int x, int y) {
  if (!x || !y)
    return x + y;
  if (nodes[x] > nodes[y])
    swap(x, y);
  rc[x] = merge(rc[x], y);
  if (dis[lc[x]] < dis[rc[x]])
    swap(lc[x], rc[x]);
  dis[x] = dis[rc[x]] + 1;
  return x;
}

int main() {
  dis[0] = -1;
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    fa[i] = nodes[i].id = i, cin >> nodes[i].val;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      if (del[x] || del[y])
        continue;
      x = find(x), y = find(y);
      if (x != y)
        fa[x] = fa[y] = merge(x, y);
    } else {
      int x;
      cin >> x;
      if (del[x]) {
        cout << "-1\n";
        continue;
      }
      x = find(x);
      cout << nodes[x].val << '\n';
      del[x] = true;
      fa[x] = fa[lc[x]] = fa[rc[x]] = merge(lc[x], rc[x]);
    }
  }
}
