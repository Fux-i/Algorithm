#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k;
	cin >> n >> k;
	unordered_map<ll, ll> cnt{};
	for (ll i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		++cnt[v];

	}
	ll sum = 0;
	priority_queue<ll> heap{};
	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
		ll mul = it->first * it->second;
		sum += mul;
		heap.emplace(mul);
	}
	for (ll i = 0; i < k && !heap.empty(); ++i) {
		ll val = heap.top();
		heap.pop();
		sum -= val;
	}
	cout << (sum < 0 ? 0 : sum);
}

/*


*/