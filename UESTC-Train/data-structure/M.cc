#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m;

ll solve(vector<ll> &a, ll k) {
	ll ans = 0;
	deque<ll> maxq{}, minq{};
	for (ll l = 0, r = 0; l < n; ++l) {
		if (maxq.empty() || minq.empty() || a[maxq.front()] - a[minq.front()] <= k)
			while (r < n) {
				while (!maxq.empty() && a[maxq.back()] < a[r]) maxq.pop_back();
				maxq.push_back(r);
				while (!minq.empty() && a[minq.back()] > a[r]) minq.pop_back();
				minq.push_back(r);
				r++;
				if (a[maxq.front()] - a[minq.front()] > k) break;
			}
		if (a[maxq.front()] - a[minq.front()] > k) {
			ans += n - r + 1;
		}
		if (maxq.front() == l) maxq.pop_front();
		if (minq.front() == l) minq.pop_front();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) cin >> a[i];

	while (m--) {
		ll k;
		cin >> k;
		cout << solve(a, k) << "\n";
	}
}

/*
5 2
1 2 3 4 5
2 3

*/