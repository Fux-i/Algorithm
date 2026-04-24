#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;
	vector<ll> v(n), t(n), sum_t(n + 1);
	vector<pll> last(n);
	for (ll i = 0; i < n; ++i) cin >> v[i];
	for (ll i = 0; i < n; ++i) cin >> t[i];
	for (ll i = 1; i <= n; ++i) sum_t[i] = t[i - 1] + sum_t[i - 1];
	for (ll i = 0; i < n; ++i) {
		ll temp_v = v[i] + sum_t[i];
		ll d = ranges::lower_bound(sum_t.begin() + i + 1, sum_t.end(), temp_v) - sum_t.begin() - 1;
		if (d == n) continue;
		last[d].first++;
		last[d].second += temp_v - sum_t[d];
	}
	ll num_alive = 0;
	for (ll i = 0; i < n; ++i) {
		num_alive++;
		num_alive -= last[i].first;
		cout << num_alive * t[i] + last[i].second << " \n"[i == n - 1];
	}
}

/*
3
10 10 5
5 7 2

5 12 4

5
30 25 20 15 10
9 10 12 4 13

9 20 35 11 25

*/