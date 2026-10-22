#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n;
struct Node {
  ll a, b, d;
} nodes[maxn];

void solve() {
  cin >> n;
  ll min_a = numeric_limits<ll>::max(), sum_b = 0;
  for (int i = 1; i <= n; i++) {
    ll ai, bi;
    cin >> ai >> bi;
    nodes[i] = {ai, bi, ai - bi};
    min_a = min(min_a, ai);
    sum_b += bi;
  }
  sort(nodes + 1, nodes + 1 + n,
       [](const Node &x, const Node &y) { return x.d < y.d; });

  ll ans = sum_b + ll(n) * min_a, pref = 0;
  for (int i = 0; i <= n; i++) {
    if (i > 0)
      pref += nodes[i].d;
    ans = min(ans, sum_b + pref + max(0, n - 2 * i) * min_a);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
