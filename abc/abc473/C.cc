#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, k;
unordered_map<int, int> cls;

void solve() {
  cin >> n >> k;
  int cnt = 0, m = 0;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    m = max(++cls[c], m);
  }
  for (auto [i, v] : cls) {
    if (v > m - 2)
      cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
