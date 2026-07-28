#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 11;
int n, p[maxn], q[maxn];
int r[maxn];
bool ap[maxn];

int get_idx(int v[]) {
  int idx = 1;
  for (int i = 1; i <= n; i++)
    ap[i] = false;
  for (int i = 1; i < n; i++) {
    int x = v[i];
    int d = 0;
    for (int j = 1; j < x; j++)
      if (ap[j])
        d++;
    int p = x - 1 - d;
    idx += p * r[n - i];
    ap[x] = true;
  }
  return idx;
}

void solve() {
  cin >> n;
  r[1] = 1;
  for (int i = 2; i <= n; i++)
    r[i] = r[i - 1] * i;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }
  int ip = get_idx(p);
  int iq = get_idx(q);
  int ans = iq - ip - 1;
  cout << (ans < 0 ? 0 : ans);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
