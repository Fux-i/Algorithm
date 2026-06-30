#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 2;
int h, w, q, r, c;
char x;

struct P {
  int a;
  char b;
};
vector<P> g[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> h >> w >> q;
  for (int i = 1; i <= h + 1; ++i) {
    g[i].assign(w + 2, {-1, 0});
  }
  g[h][w] = {0, 'A'};
  for (int i = 1; i <= q; ++i) {
    cin >> r >> c >> x;
    g[r][c] = {i, x};
  }
  for (int i = h; i > 0; i--) {
    for (int j = w; j > 0; j--) {
      auto &t = g[i][j];
      if (t.a < g[i + 1][j].a)
        t = g[i + 1][j];
      if (t.a < g[i][j + 1].a)
        t = g[i][j + 1];
    }
  }
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cout << g[i][j].b;
    }
    cout << '\n';
  }
}
