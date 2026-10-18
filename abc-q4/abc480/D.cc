// -presum -ll

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 1e5 + 2;
int n, q;
ll a[maxn], pre[maxn], prepre[maxn];
ll idx[maxn], cnt[maxn];

ll get(ll l, ll r) {
  ll c = upper_bound(idx + 1, idx + 1 + n, l) - idx - 1;
  ll d = upper_bound(idx + 1, idx + 1 + n, r) - idx - 1;
  l = l - idx[c] + 1, r = r - idx[d] + 1;
  // printf("block %lld[%d] ~ %lld[%d] ", c, l, d, r);
  if (c == d) {
    return pre[r] - pre[l - 1];
  }
  ll pl = pre[c] - pre[l - 1], pr = pre[r] - pre[0],
     mid = prepre[d - 1] - prepre[c];
  return pl + pr + mid;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    prepre[i] = prepre[i - 1] + pre[i];
  }
  for (ll i = 1, j = 1; i <= n; i++) {
    idx[i] = j;
    j += i;
  }
  for (int i = 1; i <= q; i++) {
    ll l, r;
    cin >> l >> r;
    printf("%lld\n", get(l, r));
    // cout << get(l, r) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
