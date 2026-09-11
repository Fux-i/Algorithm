#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, a[maxn], ans[maxn], l, r;
int odd[maxn], even[maxn];

void solve() {
  bool luse = false, ruse = false;
  int oi = 0, ei = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  l = a[0], r = a[1];
  if (l > r)
    swap(l, r);
  for (int i = 2; i < n; i++) {
    if (a[i] > l) {
      l = a[i];
      if (l > r)
        swap(l, r);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!luse && a[i] == l) {
      luse = true;
      continue;
    }
    if (!ruse && a[i] == r) {
      ruse = true;
      continue;
    }
    if (a[i] & 1)
      odd[oi++] = a[i];
    else
      even[ei++] = a[i];
  }
  bool is_odd = l & 1;
  int i = 1;
  ans[0] = l;
  while (oi > 0 || ei > 0) {
    if ((is_odd || oi == 0) && ei > 0) {
      ans[i++] = even[--ei];
      is_odd = false;
    } else {
      ans[i++] = odd[--oi];
      is_odd = true;
    }
  }
  ans[i] = r;
  ll sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += (ans[i] + ans[i + 1]) / 2;
  }
  cout << sum << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
