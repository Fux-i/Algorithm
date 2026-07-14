// -2d -reverse

#include <iostream>

using namespace std;
using ll = long long;
using pii = struct { int a, b; };
constexpr int maxn = 3e5 + 2;
int n, m, r[maxn], c[maxn], ans = 0;
bool rb[maxn], cb[maxn];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> r[i] >> c[i];
  }
  for (int i = m; i > 0; --i) {
    int ri = r[i], ci = c[i];
    if (!rb[ri] && !cb[ci])
      ans++;
    rb[ri] = true, cb[ci] = true;
  }
  cout << ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}
