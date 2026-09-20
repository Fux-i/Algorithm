#include <compare>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr int MOD = 998244353;
int n;

template <int MOD> struct modint {
  int _v;

  modint() : _v(0) {}
  modint(long long v) {
    if (v < 0)
      v = v % MOD + MOD;
    _v = v % MOD;
  }
  std::strong_ordering operator<=>(const modint &) const = default;
  // operator int() const { return _v; }
  // operator long long() const { return _v; }
  int val() const { return _v; }

  modint operator+(const modint &other) const {
    int res = _v + other._v;
    if (res >= MOD)
      res -= MOD;
    return modint(res);
  }
  modint &operator+=(const modint &other) {
    *this = *this + other;
    return *this;
  }
  modint operator-(const modint &other) const {
    int res = _v - other._v;
    if (res < 0)
      res += MOD;
    return modint(res);
  }
  modint &operator-=(const modint &other) {
    *this = *this - other;
    return *this;
  }

  modint operator*(const modint &other) const {
    return modint(1LL * _v * other._v % MOD);
  }
  modint &operator*=(const modint &other) {
    *this = *this * other;
    return *this;
  }

  modint pow(long long n) const {
    modint res = 1, base = *this;
    while (n > 0) {
      if (n & 1)
        res *= base;
      base *= base;
      n >>= 1;
    }
    return res;
  }

  // divide (multiply by inverse)
  modint inv() const { return pow(MOD - 2); }

  modint operator/(const modint &other) const { return *this * other.inv(); }
  modint &operator/=(const modint &other) {
    *this = *this / other;
    return *this;
  }

  modint &operator++() {
    *this += 1;
    return *this;
  }
  modint operator++(int) {
    modint tmp = *this;
    ++*this;
    return tmp;
  }
  modint &operator--() {
    *this -= 1;
    return *this;
  }
  modint operator--(int) {
    modint tmp = *this;
    --*this;
    return tmp;
  }
};

using mint = modint<MOD>;

void solve() {
  cin >> n;
  vector<int> to(2 * n, 0), nxt(2 * n, 0), h(n + 1, 0);
  int idx = 0;
  auto add = [&](int a, int b) { nxt[++idx] = h[a], to[idx] = b, h[a] = idx; };
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }

  vector<int> sz(n + 1, 1), pa(n + 1, 0), order;
  order.reserve(n);
  vector<int> st = {1};
  while (!st.empty()) {
    int u = st.back();
    st.pop_back();
    order.push_back(u);
    for (int e = h[u]; e; e = nxt[e]) {
      int v = to[e];
      if (v == pa[u])
        continue;
      pa[v] = u;
      st.push_back(v);
    }
  }

  vector<ll> cnt(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    int u = order[i];
    if (pa[u] == 0)
      continue;
    cnt[sz[u]]++;
    sz[pa[u]] += sz[u];
  }

  vector<mint> inv(n + 1), pre(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = mint(-(MOD / i)) * inv[MOD % i];
  mint comb = 1;
  pre[0] = 1;
  for (int r = 1; r <= n; r++) {
    comb *= mint(n - r + 1) * inv[r];
    pre[r] = pre[r - 1] + comb;
  }

  mint p2 = mint(2).pow(n - 1);
  vector<mint> fa(n + 1);
  for (int k = 1; k <= n - 1; k++)
    fa[k] = fa[k - 1] + p2 - pre[k - 1];

  mint ans = 0;
  for (int k = 1; k <= n - 1; k++)
    ans += fa[k] * cnt[k];
  cout << ans.val() << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}
