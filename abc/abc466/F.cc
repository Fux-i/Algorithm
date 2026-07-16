// -math

#include <climits>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
ll n, x, a, last = LLONG_MAX;

void solve() {
  cin >> n >> x;
  last = LLONG_MAX;
  priority_queue<pll, vector<pll>, less<>> h;
  h.emplace(x + 1, 1);
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a >= last)
      continue;
    last = a;
    while (!h.empty() && h.top().fi > a) {
      auto [r, k] = h.top();
      h.pop();
      while (!h.empty() && r == h.top().fi) {
        k += h.top().se, h.pop();
      }
      h.emplace(a, k * (r / a));
      if (ll d = r % a)
        h.emplace(d, k);
    }
  }
  ll sum = 0;
  while (!h.empty()) {
    ll k = h.top().se;
    sum += k;
    h.pop();
  }
  cout << sum - 1 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
