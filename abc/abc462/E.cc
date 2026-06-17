#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;

ll get(ll cx, ll cd, ll x, ll y) {
  ll dx = min(x, y);
  ll dd = max(x, y) - dx;
  return dx * cx + dd / 2 * cd;
}

void solve() {
  ll a, b, x, y, cx, cd;
  cin >> a >> b >> x >> y;
  x = abs(x);
  y = abs(y);
  if (a > b) {
    swap(a, b);
    swap(x, y);
  }
  cx = 2 * min(a, b);
  cd = 3 * a > b ? a + b : 4 * a;
  if ((x + y) & 1)
    cout << min(get(cx, cd, x - 1, y) + a, get(cx, cd, x, y - 1) + 3 * a)
         << '\n';
  else
    cout << get(cx, cd, x, y) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
