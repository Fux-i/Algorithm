#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 102;
int n;
int cnt[maxn];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    cnt[v]++;
  }
  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    if (cnt[i] & 1)
      sum += i;
  }

  cout << sum << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
