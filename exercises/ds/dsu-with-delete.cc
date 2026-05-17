// https://www.luogu.com.cn/problem/SP5150
// tag -dsu-with-delete

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct DSU {
  size_t id;
  vector<size_t> pa, size;

  explicit DSU(size_t n, size_t m)
      : id(n * 2), pa(n * 2 + m), size(n * 2 + m, 1) {
    iota(pa.begin(), pa.begin() + n, n);
    iota(pa.begin() + n, pa.end(), n);
  }

  size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y)
      return;
    if (size[x] < size[y])
      swap(x, y);
    pa[y] = x;
    size[x] += size[y];
  }

  void erase(size_t x) {
    size_t y = find(x);
    --size[y];
    pa[x] = id++;
  }
};

int main() {
  int n, m, case_id = 0;
  while ((cin >> n >> m), n) {
    DSU dsu(n, m);
    for (; m; --m) {
      char ch;
      cin >> ch;
      if (ch == 'M') {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
      } else if (ch == 'S') {
        int x;
        cin >> x;
        dsu.erase(x);
      }
    }
    int res = 0;
    for (int i = n; i < dsu.id; ++i) {
      if (dsu.size[i] && i == dsu.find(i)) {
        ++res;
      }
    }
    cout << "Case #" << (++case_id) << ": " << res << '\n';
  }
  return 0;
}
