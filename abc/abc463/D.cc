#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pii = struct {
  int l, r;
};
constexpr int maxn = 2e5 + 2;
int n, k, lb = 1, rb = 1;
vector<pii> v;

bool check(int d) {
  int ri = v[0].r, cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (ri + d <= v[i].l) {
      ri = v[i].r;
      if (++cnt == k)
        return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> k;
  v.assign(n, {});
  for (int i = 0; i < n; ++i) {
    cin >> v[i].l >> v[i].r;
    rb = max(rb, v[i].r);
  }
  sort(v.begin(), v.end(), [](pii &l, pii &r) {
    if (l.r == r.r)
      return l.l < r.l;
    return l.r < r.r;
  });
  int mid = (lb + rb) >> 1, ans = -1;
  while (lb < rb) {
    if (check(mid)) {
      lb = mid + 1;
      ans = max(ans, mid);
    } else {
      rb = mid;
    }
    mid = (lb + rb) >> 1;
  }
  cout << ans;
}
