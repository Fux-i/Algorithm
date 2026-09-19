#include <iostream>

using namespace std;
#define lc (idx << 1)
#define rc (idx << 1) + 1
#define mid l + ((r - l) >> 1)
constexpr int maxn = 2e5 + 2;
int n, m;
int p[maxn];

struct Node {
  int min, max, min_idx, max_idx;
} tree[maxn * 4];

Node merge(const Node &a, const Node &b) {
  Node res;
  if (a.min <= b.min) {
    res.min = a.min;
    res.min_idx = a.min_idx;
  } else {
    res.min = b.min;
    res.min_idx = b.min_idx;
  }
  if (a.max >= b.max) {
    res.max = a.max;
    res.max_idx = a.max_idx;
  } else {
    res.max = b.max;
    res.max_idx = b.max_idx;
  }
  return res;
}

void build(int l, int r, int idx) {
  if (l == r) {
    tree[idx] = {p[l], p[l], l, l};
    return;
  }
  build(l, mid, lc);
  build(mid + 1, r, rc);
  tree[idx] = merge(tree[lc], tree[rc]);
}

Node query(int ql, int qr, int l, int r, int idx) {
  if (ql <= l && r <= qr) return tree[idx];
  if (qr <= mid) return query(ql, qr, l, mid, lc);
  if (ql > mid) return query(ql, qr, mid + 1, r, rc);
  return merge(query(ql, qr, l, mid, lc), query(ql, qr, mid + 1, r, rc));
}

void update(int pos, int val, int l, int r, int idx) {
  if (l == r) {
    tree[idx] = {val, val, l, l};
    return;
  }
  if (pos <= mid) update(pos, val, l, mid, lc);
  else update(pos, val, mid + 1, r, rc);
  tree[idx] = merge(tree[lc], tree[rc]);
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i];
  build(1, n, 1);
  while (m--) {
    int l, r;
    cin >> l >> r;
    Node res = query(l, r, 1, n, 1);
    swap(p[res.min_idx], p[res.max_idx]);
    update(res.min_idx, p[res.min_idx], 1, n, 1);
    update(res.max_idx, p[res.max_idx], 1, n, 1);
  }
  for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}
