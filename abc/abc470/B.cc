#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 102;
int n, m[maxn];

void solve() {
  cin >> n;
  int _max = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    _max = max(_max, ++m[v]);
  }
  cout << n - _max << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
