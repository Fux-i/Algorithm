#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 5e5 + 2;
int h, w, k;

void solve() {
  cin >> h >> w >> k;
  vector<string> s(h);
  vector<bool> row(h), col(w);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  vector<int> dis(h * w, -1);
  queue<int> q;
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.' && !row[i] && !col[j]) {
        dis[i * w + j] = 0;
        q.emplace(i * w + j);
        ans++;
      }
    }
  }

  constexpr int dx[] = {-1, 1, 0, 0};
  constexpr int dy[] = {0, 0, -1, 1};
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dis[u] == k)
      continue;
    int x = u / w, y = u % w;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#')
        continue;
      int v = nx * w + ny;
      if (dis[v] != -1)
        continue;
      dis[v] = dis[u] + 1;
      q.emplace(v);
      ans++;
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
