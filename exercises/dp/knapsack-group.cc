// https://www.luogu.com.cn/problem/P1757
// tag: -knapsack -group

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;
constexpr int maxn = 1002, maxk = 102;
int n, m, k, a[maxn], b[maxn], dp[maxn];
vector<int> g[maxk];
unordered_map<int, int> ctog;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> a[i] >> b[i] >> c;
    if (ctog.contains(c))
      g[ctog[c]].push_back(i);
    else
      ctog[c] = ++k, g[k].push_back(i);
  }
  for (int ki = 1; ki <= k; ++ki) {
    for (int j = m; j > 0; --j) {
      for (int i : g[ki]) {
        if (a[i] <= j) {
          dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
      }
    }
  }
  cout << dp[m];
}
