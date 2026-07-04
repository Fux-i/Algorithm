#include <iostream>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x, y, k;
    cin >> x >> y >> k;
    int ans = 0;
    while (x != y) {
      if (x > y)
        x /= k;
      else
        y /= k;
      ++ans;
    }
    cout << ans << '\n';
  }
}
