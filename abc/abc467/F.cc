// -segtree

#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<int, int>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 5;
int n, q, off = 0;
int a[maxn], b[maxn];
int pos[maxn];
int loc[maxn];
pll ord_b[maxn];
struct query {
  int t, i, x;
} qs[maxn];

#define lc (idx << 1)
#define rc (idx << 1 | 1)
#define mid ((l + r) >> 1)
struct segtree {
  ll sum[maxn << 2];
  ll mx[maxn << 2];

  void up(int idx) {
    sum[idx] = sum[lc] + sum[rc];
    mx[idx] = max(mx[lc], sum[lc] + mx[rc]);
  }
  void build(int idx, int l, int r) {
    if (l == r) {
      int id = ord_b[l].se;
      if (id > n) {
        sum[idx] = 0, mx[idx] = 0;
      } else {
        sum[idx] = a[id];
        mx[idx] = (ll)a[id] + ord_b[l].fi;
      }
      return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(idx);
  }
  void change(int idx, int l, int r, int p, ll A, ll B, bool empty) {
    if (l == r) {
      if (empty)
        sum[idx] = 0, mx[idx] = 0;
      else
        sum[idx] = A, mx[idx] = A + B;
      return;
    }
    if (p <= mid)
      change(lc, l, mid, p, A, B, empty);
    else
      change(rc, mid + 1, r, p, A, B, empty);
    up(idx);
  }
} t;

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    ord_b[++off] = {b[i], i};
  }
  for (int i = 1; i <= q; i++) {
    cin >> qs[i].t >> qs[i].i >> qs[i].x;
    if (qs[i].t == 2) {
      ord_b[++off] = {qs[i].x, n + i};
    }
  }

  sort(ord_b + 1, ord_b + 1 + off, greater<>());

  for (int p = 1; p <= off; p++)
    loc[ord_b[p].se] = p;
  for (int i = 1; i <= n; i++)
    pos[i] = loc[i];

  t.build(1, 1, off);

  for (int j = 1; j <= q; j++) {
    auto [type, i, x] = qs[j];
    if (type == 1) {
      a[i] = x;
      t.change(1, 1, off, pos[i], a[i], b[i], false);
    } else {
      t.change(1, 1, off, pos[i], 0, 0, true);
      b[i] = x;
      pos[i] = loc[n + j];
      t.change(1, 1, off, pos[i], a[i], b[i], false);
    }
    cout << t.mx[1] << '\n';
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
