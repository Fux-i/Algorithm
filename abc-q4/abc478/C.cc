// -segtree
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
#define lc ((idx << 1) + 1)
#define rc ((idx << 1) + 2)
#define mid (l + ((r - l) >> 1))

constexpr int maxn = 2e5 + 5;
int n, k, a[maxn];

struct Node {
  int min, max;
  bool sorted;
} tree[maxn << 2];

Node merge(const Node &a, const Node &b) {
  Node c;
  c.min = min(a.min, b.min);
  c.max = max(a.max, b.max);
  c.sorted = a.sorted && b.sorted && a.max <= b.min;
  return c;
}

void build(int l, int r, int idx) {
  if (l == r) {
    tree[idx].min = tree[idx].max = a[l];
    tree[idx].sorted = true;
    return;
  }
  build(l, mid, lc);
  build(mid + 1, r, rc);
  tree[idx] = merge(tree[lc], tree[rc]);
}

Node query(int l, int r, int idx, int ql, int qr) {
  if (ql <= l && r <= qr)
    return tree[idx];
  if (qr <= mid)
    return query(l, mid, lc, ql, qr);
  if (ql > mid)
    return query(mid + 1, r, rc, ql, qr);
  return merge(query(l, mid, lc, ql, qr), query(mid + 1, r, rc, ql, qr));
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = 0;
  a[n + 1] = INT_MAX;
  build(0, n + 1, 0);
  bool possible = false;
  for (int i = 0; i <= n - k; i++) {
    Node win = query(0, n + 1, 0, i + 1, i + k);
    Node pre = query(0, n + 1, 0, 0, i);
    Node suf = query(0, n + 1, 0, i + k + 1, n + 1);
    if (pre.sorted && suf.sorted && pre.max <= win.min && win.max <= suf.min) {
      possible = true;
      break;
    }
  }
  cout << (possible ? "Yes\n" : "No\n");
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
