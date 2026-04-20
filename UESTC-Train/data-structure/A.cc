#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

vector<ll> dsu, sizes;

ll find(ll x) {
	return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void unite(ll x, ll y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sizes[x] < sizes[y]) swap(x, y);
	dsu[y] = x;
	sizes[x] += sizes[y];
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}

struct circle {
	ll x, y, r;
};

bool check(circle &a, circle &b) {
	double dis = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return dis <= static_cast<double>(a.r) + static_cast<double>(b.r);
}

vector<circle> cs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, y11, y22;
	cin >> n >> y11 >> y22;
	dsu.assign(n + 2, 0);
	sizes.assign(n + 2, 1);
	iota(dsu.begin(), dsu.end(), 0);
	cs.assign(n + 1, {});
	for (ll i = 1; i <= n; ++i) cin >> cs[i].x >> cs[i].y >> cs[i].r;

	for (ll i = 1; i <= n; ++i) {
		circle &c = cs[i];
		if (abs(c.y - y11) <= c.r) unite(i, 0);
		if (abs(c.y - y22) <= c.r) unite(i, n + 1);
		if (same(0, n + 1)) {
			cout << "Yes\n";
			return 0;
		}
	}

	for (ll i = 1; i < n; ++i) {
		for (ll j = 1; i + j <= n; ++j) {
			auto &c1 = cs[i], c2 = cs[i + j];
			if (check(c1, c2)) unite(i, i + j);
			if (same(0, n + 1)) {
				cout << "Yes\n";
				return 0;
			}
		}
	}

	cout << "No\n";
}
