#include <iostream>
#include <set>

using namespace std;
using pi = pair<int, int>;
#define fi first
#define se second
constexpr int maxn = 3e5 + 2;
int n, q;
char ans[maxn];
pi qs[maxn];
set<int> s;
bool tiles[maxn];

void solve() {
  cin >> n >> q;
  // s.reserve(n);
  for (int i = 1; i <= n; i++) {
    s.insert(i);
    tiles[i] = false;
  }
  qs[0] = {2, 'a'};
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      tiles[v] = !tiles[v];
      if (tiles[v])
        s.erase(v);
      else
        s.insert(v);
      qs[i] = {1, v};
    } else {
      char c;
      cin >> c;
      qs[i] = {2, c};
    }
  }
  for (int i = q; i >= 0; i--) {
    auto [t, v] = qs[i];
    if (t == 2) {
      char c = v;
      for (auto x : s) {
        ans[x] = c;
        tiles[x] = true;
      }
      s.clear();
    } else {
      if (ans[v] == 0) {
        tiles[v] = !tiles[v];
        if (tiles[v])
          s.erase(v);
        else
          s.insert(v);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i];
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
