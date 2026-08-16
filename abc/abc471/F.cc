// -string

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct Item {
  string s;
  int len;
  ll val;
};

string strip(const string &s) {
  int i = 0;
  while (i + 1 < (int)s.size() && s[i] == '0')
    i++;
  return s.substr(i);
}

bool better(const string &a, const string &b) {
  if (a.size() != b.size())
    return a.size() > b.size();
  return a > b;
}

string concat_max(vector<string> v) {
  sort(v.begin(), v.end(),
       [](const string &a, const string &b) { return a + b > b + a; });
  string res;
  res.reserve(v.size() * 10);
  for (auto &x : v)
    res += x;
  return strip(res);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<Item> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].s;
    a[i].len = (int)a[i].s.size();
    a[i].val = 0;
    for (char c : a[i].s)
      a[i].val = a[i].val * 10 + (c - '0');
  }
  sort(a.begin(), a.end(), [](const Item &x, const Item &y) {
    if (x.len != y.len)
      return x.len > y.len;
    return x.val > y.val;
  });

  auto build = [&](const vector<int> &idx) {
    vector<string> v;
    v.reserve(idx.size());
    for (int i : idx)
      v.push_back(a[i].s);
    return concat_max(move(v));
  };

  vector<int> s1(k);
  for (int i = 0; i < k; i++)
    s1[i] = i;
  string ans = build(s1);

  if (k < n) {
    int best = k;
    for (int i = k + 1; i < n; i++)
      if (a[i].val > a[best].val)
        best = i;
    vector<int> s2;
    s2.reserve(k);
    for (int i = 0; i < k - 1; i++)
      s2.push_back(i);
    s2.push_back(best);
    string cand = build(s2);
    if (better(cand, ans))
      ans = cand;
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
