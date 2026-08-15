#include <compare>
#include <iostream>

// MOD MUST be prime
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

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int MOD = 998244353;
using mint = modint<MOD>;
constexpr int maxn = 200005;
int n, k;
mint fac[maxn], ifac[maxn];

mint C(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  return fac[n] * ifac[k] * ifac[n - k];
}

void solve() {
  cin >> n >> k;
  mint s = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mint a = x;
    s += a;
    s2 += a * a;
  }
  mint ans = C(n - 1, k - 1) * s2 + C(n - 2, k - 2) * (s * s - s2);
  cout << ans.val() << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  fac[0] = 1;
  for (int i = 1; i < maxn; i++)
    fac[i] = fac[i - 1] * i;
  ifac[maxn - 1] = fac[maxn - 1].inv();
  for (int i = maxn - 1; i >= 1; i--)
    ifac[i - 1] = ifac[i] * i;
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
