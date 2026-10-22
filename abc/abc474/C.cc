#include <iostream>

using namespace std;
constexpr int maxn = 2e5 + 2;
int n, q;
int p[maxn];

struct Node {
  int val;
  Node *prev, *next;
} *nodes[maxn];

void solve() {
  cin >> n >> q;
  Node *h = new Node{}, *t = new Node{};
  Node *o = h;
  for (int i = 1; i <= n; i++) {
    Node *w = new Node{};
    cin >> w->val;
    nodes[w->val] = w;
    o->next = w;
    w->prev = o;
    o = w;
  }
  o->next = t;
  t->prev = o;
  for (int i = 1; i <= q; i++) {
    int a;
    cin >> a;
    if (nodes[a]->next == t)
      continue;
    o = nodes[a];
    o->prev->next = o->next;
    o->next->prev = o->prev;
    t->prev->next = o;
    o->prev = t->prev;
    o->next = t;
    t->prev = o;
  }
  o = h->next;
  while (o != t) {
    cout << o->val << ' ';
    o = o->next;
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
