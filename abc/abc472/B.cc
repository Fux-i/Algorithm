#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 102;
int n, l[maxn], pre[maxn], post[maxn];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    pre[i] = pre[i - 1] + l[i];
  }
  int abmin = INT_MAX;
  for (int i = n; i > 1; i--) {
    int x = post[i] = post[i + 1] + l[i];
    int y = pre[i - 1];
    abmin = min(abmin, abs(x - y));
  }

  cout << abmin;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
