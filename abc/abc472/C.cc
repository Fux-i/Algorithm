#include <deque>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, m, a[maxn];
ll k;
deque<pll> que;

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    if (!que.empty() && (i - que.front().se >= m)) {
      sum -= que.front().fi;
      que.pop_front();
    }
    if (sum + a[i] <= k) {
      sum += a[i];
      que.emplace_back(a[i], i);
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
