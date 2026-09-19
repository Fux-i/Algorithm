#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 2;
int n, m, k;
ll x, y;
int a[maxn], b[maxn], bn[maxn];
ll prea[maxn], preb[maxn], prebn[maxn];

void solve() {
  cin >> n >> m >> k >> x >> y;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; i++)
    prea[i] = prea[i - 1] + a[i];
  for (int i = 1; i <= m; i++)
    preb[i] = preb[i - 1] + b[i];
  for (int i = 1; i <= m; i++)
    bn[i] = (b[i] + k - 1) / k;

  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ll used = prebn[i] = prebn[i - 1] + bn[i];
    if (used > y)
      break;
    ll w = x + k * y - preb[i];
    int j = upper_bound(prea + 1, prea + 1 + n, w) - prea - 1;
    ans = max(ans, i + j);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
