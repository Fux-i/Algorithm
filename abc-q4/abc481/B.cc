#include <iostream>

using namespace std;
constexpr int maxn = 102;
int n, k;
int a[maxn];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int num = 0;
  for (int i = 1; i < n; i++) {
    if (i == 1 && a[i] == k || a[i + 1] == k) {
      num++;
    } else if (((a[i] - k) ^ (a[i + 1] - k)) < 0 && a[i] != k &&
               a[i + 1] != k) {
      num++;
    }
  }
  cout << num << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
