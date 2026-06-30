#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr int maxn = 3e5 + 2;
int n, m, a[maxn], d[maxn], b[maxn], cnt[maxn];
vector<int> chg[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  int ans = 0, ai, di, bi;
  for (int i = 1; i <= n; ++i) {
    cin >> ai >> di >> bi;
    a[i] = ai, d[i] = di, b[i] = bi;
    int c = di == 1 ? bi : ai;
    if (cnt[c]++ == 0) {
      ans++;
    }
    if (di != 1 && ai != bi) {
      chg[d[i]].push_back(i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j : chg[i]) {
      if (--cnt[a[j]] == 0) {
        ans--;
      }
      if (cnt[b[j]]++ == 0) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
