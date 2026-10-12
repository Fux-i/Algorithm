// -segtree

#include <algorithm>
#include <climits>
#include <iostream>

#define lc ((idx << 1) + 1)
#define rc ((idx << 1) + 2)
#define mid (l + ((r - l) >> 1))

using namespace std;

constexpr int maxn = 3e5 + 2;
int n, q, li[maxn], ri[maxn];

struct Node {
  int lm, rm;
} tree[maxn << 2];

Node merge(const Node &a, const Node &b) {
  Node c;
  c.lm = min(a.lm, b.lm);
  c.rm = min(a.rm, b.rm);
  return c;
}

void build(int l, int r, int idx) {
  if (l == r) {
    tree[idx] = {li[l], ri[r]};
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
  cin >> n >> q;
  li[1] = ri[n] = INT_MAX / 2;
  for (int i = 2; i <= n; i++)
    cin >> li[i];
  for (int i = 1; i < n; i++)
    cin >> ri[i];
  build(1, n, 0);
  for (int i = 1; i <= q; i++) {
    int s, t;
    cin >> s >> t;
    int cost;
    if (s < t) {
      cost = ri[s];
      if (s > 1)
        cost = min(cost, li[s] + query(1, n, 0, 1, s - 1).rm);
    } else {
      cost = li[s];
      if (s < n)
        cost = min(cost, ri[s] + query(1, n, 0, s + 1, n).lm);
    }
    cout << cost << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
