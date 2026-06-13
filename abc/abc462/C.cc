#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 3e5 + 2;
int n, y[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 0, x, y; i < n; ++i) {
    cin >> x >> y;
    ::y[x] = y;
  }

  int ans = 0, min_y = n + 1;
  for (int x = 1; x <= n; ++x) {
    if (y[x] < min_y)
      ++ans;
    min_y = min(min_y, y[x]);
  }
  cout << ans << '\n';
}
