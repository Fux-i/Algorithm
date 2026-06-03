// https://www.luogu.com.cn/problem/solution/P1880
// tag: -dp -interval

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 202, inf = 0x3f3f3f3f;
int n, a[maxn], sum[maxn], dp_min[maxn][maxn], dp_max[maxn][maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      dp_min[i][j] = inf;
      dp_max[i][j] = 0;
    }
    dp_min[i][i] = dp_max[i][i] = 0;
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i <= 2 * n - len + 1; ++i) {
      int j = i + len - 1;
      int range_sum = sum[j] - sum[i - 1];

      for (int k = i; k < j; ++k) {
        dp_min[i][j] =
            min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + range_sum);
        dp_max[i][j] =
            max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + range_sum);
      }
    }
  }

  int ans_min = inf, ans_max = 0;
  for (int i = 1; i <= n; i++) {
    ans_min = min(ans_min, dp_min[i][i + n - 1]);
    ans_max = max(ans_max, dp_max[i][i + n - 1]);
  }

  cout << ans_min << "\n" << ans_max << "\n";
  return 0;
}
