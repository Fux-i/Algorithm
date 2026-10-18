#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
constexpr int maxn = 102;
int n, m;
int num[maxn];
string str[maxn];
unordered_map<string, int> map;

int diff(string &s, string &t) {
  size_t ss = s.size(), st = t.size();
  if (ss != st)
    return -1;
  int cnt = 0;
  for (int i = 0; i < ss; i++) {
    if (s[i] == t[i])
      continue;
    if (++cnt == 2)
      break;
  }
  return cnt;
}

int check(string &t) {
  int cnt = 0;
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    if (diff(str[i], t) == 1) {
      if (cnt++ == 0)
        idx = i;
      else {
        return -1;
      }
    }
  }
  return idx;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    map[s] = i, str[i] = s;
  }
  for (int i = 1; i <= m; i++) {
    string t;
    cin >> t;
    if (map.contains(t)) {
      num[map[t]]++;
      // printf("num[%d]++", map[t]);
      continue;
    }
    int idx = check(t);
    if (idx > 0) {
      num[idx]++;
      // printf("num[%d]++", idx);
    }
  }
  for (int i = 1; i <= n; i++)
    cout << num[i] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
