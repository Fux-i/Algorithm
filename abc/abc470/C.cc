#include <iostream>
#include <set>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 5e5 + 2;
int n, q, m[maxn], num = 0, temp[maxn];
set<int> s{};

int lowbit(int x) { return x & -x; }

void solve() {
  cin >> n >> q;
  int ans = 0;
  for (int i = 0; i < q; i++) {
    int t, v;
    cin >> t;
    if (t == 1) {
      cin >> v;
      int x = ++m[v];
      if (x == 1) {
        num++;
        s.emplace(v);
      }
      x = lowbit(x);
      x = (x << 1) - 1;
      ans ^= x;
    } else {
      int ti = 0;
      for (int v : s) {
        int x = m[v]--;
        if (x == 1) {
          num--;
          temp[ti++] = v;
        }
        x = lowbit(x);
        x = (x << 1) - 1;
        ans ^= x;
      }
      for (int j = 0; j < ti; j++) {
        s.erase(temp[j]);
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
