// https://www.luogu.com.cn/problem/P5911
// -dp -state -bitmask

#include <iostream>
#include <limits>

using namespace std;
using ll = long long;
constexpr int maxn = 1 << 16;
int t[maxn], w[maxn], dp[maxn];
int n, W;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> W >> n;
  const int S = 1 << n;
  for (int j = 0, ti, wi; j < n; ++j) {
    cin >> ti >> wi;
    for (int i = 0; i < S; ++i) {
      if (i & (1 << j)) {
        t[i] = max(t[i], ti);
        w[i] += wi;
      }
    }
  }
  for (int i = 0; i < S; ++i)
    dp[i] = numeric_limits<int>::max() / 2;
  for (int i = 0; i < S; ++i) {
    if (w[i] <= W)
      dp[i] = t[i];
    for (int j = i; j; j = i & (j - 1))
      if (w[i ^ j] <= W)
        dp[i] = min(dp[i], dp[j] + t[i ^ j]);
  }
  cout << dp[S - 1] << '\n';
}
