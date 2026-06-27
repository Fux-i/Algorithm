#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 2;
int n;
ll x[maxn], y[maxn];
string a;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> a;
    a = " " + a;
    for (int i = 1; i <= n; ++i)
      cin >> x[i];
    for (int i = 1; i < n; ++i)
      cin >> y[i];
    ll s = a[1] == 'S' ? 0 : -x[1];
    ll r = a[1] == 'R' ? 0 : -x[1];
    for (int i = 2; i <= n; ++i) {
      ll cs = a[i] == 'S' ? 0 : -x[i];
      ll cr = a[i] == 'R' ? 0 : -x[i];
      ll ns = max(s + cs, r + cs + y[i - 1]);
      ll nr = max(s + cr, r + cr);
      s = ns, r = nr;
    }
    cout << max(s, r) << '\n';
  }
}
