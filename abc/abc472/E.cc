// -graph -cycle -dye

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, m;

void solve() {
  cin >> n >> m;
  vector<int> to(2 * m + 1, 0), nxt(2 * m + 1, 0), h(n + 1, 0);
  int idx = 0;
  auto add = [&](int a, int b) {
    nxt[++idx] = h[a];
    to[idx] = b;
    h[a] = idx;
  };
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  vector<int> color(n + 1, -1), parent(n + 1, 0);
  vector<int> cycle;

  vector<int> st = {1};
  color[1] = 0;
  while (!st.empty() && cycle.empty()) {
    int u = st.back();
    st.pop_back();

    for (int e = h[u]; e; e = nxt[e]) {
      int v = to[e];
      if (color[v] == -1) {
        color[v] = color[u] ^ 1;
        parent[v] = u;
        st.push_back(v);
      } else if (color[v] == color[u]) {
        vector<bool> on_path(n + 1, false);
        vector<int> path_u, path_v;

        for (int x = u; x; x = parent[x]) {
          on_path[x] = true;
          path_u.push_back(x);
        }

        int lca = v;
        while (!on_path[lca]) {
          path_v.push_back(lca);
          lca = parent[lca];
        }

        path_u.resize(find(path_u.begin(), path_u.end(), lca) - path_u.begin() +
                      1);
        cycle = path_u;
        for (auto it = path_v.rbegin(); it != path_v.rend(); ++it) {
          cycle.push_back(*it);
        }
        break;
      }
    }
  }

  if (cycle.empty()) {
    cout << -1 << '\n';
    return;
  }

  cout << cycle.size() << '\n';
  for (int i = 0; i < cycle.size(); i++) {
    if (i)
      cout << ' ';
    cout << cycle[i];
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
