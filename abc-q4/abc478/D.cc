// -fenwick
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, q;
vector<pair<int, int>> bucket[maxn];
int maxr[maxn], bit[maxn], total;

void add(int idx, int val) {
  for (; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int sum(int idx) {
  int res = 0;
  for (; idx > 0; idx -= idx & -idx)
    res += bit[idx];
  return res;
}

void solve() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    bucket[l].push_back({r, x});
  }
  for (int p = 1; p <= n; p++) {
    for (auto [r, x] : bucket[p]) {
      if (r > maxr[x]) {
        if (maxr[x] > 0)
          add(maxr[x], -1);
        else
          total++;
        maxr[x] = r;
        add(r, 1);
      }
    }
    cout << total - sum(p - 1);
    cout << (p == n ? '\n' : ' ');
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
