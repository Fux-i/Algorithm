#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, m;
int a[maxn], b[maxn], d[maxn], f[maxn];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  f[1] = 0;
  int sum = 0;
  for (int i = 1; i < n; i++) {
    cin >> b[i];
    d[i] = (2 + b[i] - a[i] - a[i + 1]) & 1;
    f[i + 1] = f[i] ^ d[i];
    sum += f[i + 1];
  }
  cout << min(sum, n - sum) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
