// https://atcoder.jp/contests/abc469/tasks/abc469_e
// -math 把区间胜率大于 p 转变为区间和大于 0

#include <iomanip>
#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 2;
int n, k;
string s;
double S[maxn], pm[maxn];

// 判断是否存在合法区间（胜场 ≥ k）胜率 ≥ p
bool check(double p) {
  S[0] = 0;
  pm[0] = 0;
  for (int i = 1; i <= n; i++) {
    S[i] = S[i - 1] + (s[i - 1] == 'o' ? 1 - p : -p);
    pm[i] = min(pm[i - 1], S[i]);
  }
  // 滑动窗口：对每个右端点 r，求最大的 l 使得 [l, r] 内有 ≥k 个 o
  int l = 1, cnt = 0;
  for (int r = 1; r <= n; r++) {
    if (s[r - 1] == 'o')
      cnt++;
    // 尽量把 l 往右推，仍保证去掉 s[l-1] 后胜场 ≥ k
    while (cnt - (s[l - 1] == 'o') >= k) {
      cnt -= (s[l - 1] == 'o');
      l++;
    }
    // 若存在 l' ≤ l_r 使 S[l'-1] ≤ S[r]，则可行
    if (cnt >= k && pm[l - 1] <= S[r] + 1e-12)
      return true;
  }
  return false;
}

void solve() {
  cin >> n >> k >> s;
  double lo = 0, hi = 1;
  for (int it = 0; it < 70; it++) {
    double mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << fixed << setprecision(12) << lo << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
