#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 1;
int n;
priority_queue<int> neg;
priority_queue<int, vector<int>, greater<>> pos;

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0)
      neg.emplace(x);
    else
      pos.emplace(x);
  }
  ll sum = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    if (neg.empty()) {
      int db = pos.top() - cur;
      sum += db, cur += db;
      pos.pop();
      continue;
    }
    if (pos.empty()) {
      int da = cur - neg.top();
      sum += da, cur -= da;
      neg.pop();
      continue;
    }
    int db = pos.top() - cur;
    int da = cur - neg.top();
    if (da <= db) {
      sum += da;
      cur -= da;
      neg.pop();
    } else {
      sum += db;
      cur += db;
      pos.pop();
    }
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
