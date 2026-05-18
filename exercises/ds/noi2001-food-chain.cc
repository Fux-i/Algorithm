// https://www.luogu.com.cn/problem/P2024
// dsu

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct dsu {
  vector<int> fa, siz;
  dsu(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }

  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

  bool same(int x, int y) { return find(x) == find(y); }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return;
    if (siz[x] < siz[y])
      swap(x, y);
    fa[y] = x;
    siz[x] += siz[y];
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  dsu d(n * 3 + 1);
  int ans = 0;

  for (int i = 0; i < k; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    if (x > n || y > n)
      ans++;
    else if (t == 1) {
      if (d.same(x, y + n) || d.same(x, y + 2 * n))
        ans++;
      else {
        d.unite(x, y);
        d.unite(x + n, y + n);
        d.unite(x + 2 * n, y + 2 * n);
      }
    } else {
      if (d.same(x, y) || d.same(x, y + n))
        ans++;
      else {
        d.unite(x, y + 2 * n);
        d.unite(x + n, y);
        d.unite(x + 2 * n, y + n);
      }
    }
  }
  cout << ans << '\n';
}
