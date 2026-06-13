#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxd = 1e6 + 2;
int n, D;
ll diff[maxd];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> D;
  for (int i = 0, s, t; i < n; ++i) {
    cin >> s >> t;
    int r = t - D;
    if (s <= r) {
      ++diff[s];
      --diff[r + 1];
    }
  }

  ll ans = 0, cnt = 0;
  for (int x = 1; x < maxd; ++x) {
    cnt += diff[x];
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << '\n';
}
