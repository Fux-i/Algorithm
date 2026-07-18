#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int x1, y1, x2, y2, x3, y3, x4, y4;

void solve() {
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ll a1 = x2 - x1, b1 = y2 - y1;
  ll c1 = 1LL * x2 * x2 + 1LL * y2 * y2 - 1LL * x1 * x1 - 1LL * y1 * y1;
  ll a2 = x4 - x3, b2 = y4 - y3;
  ll c2 = 1LL * x4 * x4 + 1LL * y4 * y4 - 1LL * x3 * x3 - 1LL * y3 * y3;
  auto cross = [](ll p, ll q, ll r, ll s) -> __int128 {
    return (__int128)p * q - (__int128)r * s;
  };
  if (cross(a1, b2, a2, b1) != 0 ||
      (cross(a1, c2, a2, c1) == 0 && cross(b1, c2, b2, c1) == 0))
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
