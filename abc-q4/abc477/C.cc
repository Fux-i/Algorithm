#include <iostream>
#include <string>

using namespace std;
constexpr int maxn = 4e5 + 2;
int q, in[maxn], ini = 0;
string s, t;

void solve() {
  cin >> q >> s >> t;
  int i = 0, siz = s.size(), tsiz = t.size();
  while (1) {
    int idx = s.find(t, i);
    if (idx == -1)
      break;
    in[ini++] = idx + 1;
    i = idx + 1;
  }
  for (int j = 1; j <= q; j++) {
    int l, r;
    cin >> l >> r;
    auto pos = lower_bound(in, in + ini, l);
    if (pos == in + ini || *pos + tsiz - 1 > r)
      cout << "No\n";
    else
      cout << "Yes\n";
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
