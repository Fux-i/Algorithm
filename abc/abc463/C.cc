#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int maxq = 3e5 + 2;
pii qs[maxq], ans[maxq];
int n, q;
priority_queue<pii, vector<pii>, less<>> heap;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int h, l;
    cin >> h >> l;
    heap.emplace(h, l);
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> qs[i].first;
    qs[i].second = i;
  }
  sort(qs + 1, qs + q + 1);
  for (int i = 1; i <= q; ++i) {
    while (heap.top().second <= qs[i].first) {
      heap.pop();
    }
    ans[i].first = qs[i].second, ans[i].second = heap.top().first;
  }
  sort(ans + 1, ans + 1 + q);
  for (int i = 1; i <= q; ++i)
    cout << ans[i].second << '\n';
}
