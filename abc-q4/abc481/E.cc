// -math -precision(long double)

#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;
using ldb = long double;
constexpr int maxn = 2e5 + 2;
int n;
int ti = 0, nti = 0;
ldb tanv[maxn], ntanv[maxn];

void solve() {
  cin >> n;
  ti = 0, nti = 0;
  for (int i = 0; i < n; i++) {
    ldb x, y;
    cin >> x >> y;
    if (x > 0)
      tanv[ti++] = y / x;
    else if (x < 0)
      ntanv[nti++] = y / x;
    else if (y > 0)
      tanv[ti++] = numeric_limits<ldb>::max();
    else
      ntanv[nti++] = numeric_limits<ldb>::max();
  }
  sort(tanv, tanv + ti), sort(ntanv, ntanv + nti);
  int ans = max(ti, nti);
  for (int i = 0; i < ti; i++) {
    int nidx = lower_bound(ntanv, ntanv + nti, tanv[i]) - ntanv;
    int one_side = ti - i + nidx;
    ans = max(ans, one_side);
    ans = max(ans, n - one_side);
  }
  for (int i = 0; i < nti; i++) {
    int idx = lower_bound(tanv, tanv + ti, ntanv[i]) - tanv;
    int one_side = nti - i + idx;
    ans = max(ans, one_side);
    ans = max(ans, n - one_side);
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
