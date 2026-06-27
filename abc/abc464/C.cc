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
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> d[i] >> b[i];
    int c = d[i] == 1 ? b[i] : a[i];
    if (cnt[c] == 0)
      ans++;
    cnt[c]++;
    if (d[i] > 1 && a[i] != b[i])
      chg[d[i]].push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    for (int j : chg[i]) {
      cnt[a[j]]--;
      if (cnt[a[j]] == 0)
        ans--;
      if (cnt[b[j]] == 0)
        ans++;
      cnt[b[j]]++;
    }
    cout << ans << '\n';
  }
}
