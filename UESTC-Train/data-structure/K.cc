#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr ll mod = 1e9 + 7, maxn = 1e5 + 2;
ll n, siz, q, p[maxn][5], c[maxn], cnt[maxn], l = 1, r = 0, acc[5] = {0, 0, 0, 0, 0}, ans[maxn];

struct Q {
	ll l, r, k, b, id;

	bool operator<(const Q &x) const {
		if (b != x.b) return l < x.l;
		return b & 1 ? r > x.r : r < x.r;
	}
} qs[maxn];

void pre() {
	for (int i = 1; i <= n; ++i) {
		ll x = 1;
		for (int k = 0; k < 5; ++k) {
			x = x * i % mod;
			p[i][k] = x;
		}
	}
}

void add(ll i) {
	ll ci = c[i];
	ll cnti = cnt[ci];
	ll new_cnti = ++cnt[ci];
	for (int k = 0; k < 5; ++k) acc[k] = (acc[k] - p[cnti][k] + p[new_cnti][k] + mod) % mod;
	// cout << format("[{},{}]: {}\n", l, r, acc[1]);
}
void del(ll i) {
	ll ci = c[i];
	ll cnti = cnt[ci];
	ll new_cnti = --cnt[ci];
	for (int k = 0; k < 5; ++k) acc[k] = (acc[k] - p[cnti][k] + p[new_cnti][k] + mod) % mod;
	// cout << format("[{},{}]: {}\n", l, r, acc[1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	siz = sqrt(n);
	pre();
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 0; i < q; ++i) {
		cin >> qs[i].l >> qs[i].r >> qs[i].k;
		qs[i].b = qs[i].l / siz;
		qs[i].id = i;
	}
	sort(qs, qs + q);
	for (int i = 0; i < q; ++i) {
		auto [li, ri, k, _, id] = qs[i];
		while (r < ri) add(++r);
		while (l > li) add(--l);
		while (r > ri) del(r--);
		while (l < li) del(l++);
		ans[id] = acc[k - 1];
	}
	for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}

/*
6 6
1 1 4 5 1 4
1 4 2
2 6 2
3 5 3
5 6 1
1 1 4
1 5 4


*/
