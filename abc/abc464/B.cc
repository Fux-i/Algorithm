#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 52;
int n, m;
char g[maxn][maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  int r = 0, l = m - 1, b = 0, t = n - 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      g[i][j] = c;
      if (c == '#') {
        t = min(t, i);
        b = max(b, i);
        l = min(l, j);
        r = max(r, j);
      }
    }
  for (int i = t; i <= b; ++i) {
    for (int j = l; j <= r; ++j) {
      cout << g[i][j];
    }
    cout << '\n';
  }
}
