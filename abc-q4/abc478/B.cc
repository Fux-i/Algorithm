#include <algorithm>
#include <iostream>

using namespace std;
constexpr int maxn = 102;
int n, v;
int w[maxn];

void solve() {
  cin >> n >> v;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (i + j + k + 3 > v)
          break;
        int sum = w[i] + w[j] + w[k];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
