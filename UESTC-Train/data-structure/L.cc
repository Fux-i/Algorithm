#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

constexpr ll maxn = 1e5 + 2;

void solve() {
	ll n, t, l[3];
	cin >> n >> l[0] >> l[1] >> l[2];
	vector<ll> p(maxn), c(maxn), duty(3), rest(3);
	priority_queue<pll, vector<pll>, greater<>> heap{};
	for (int i = 1; i <= n; ++i) {
		ll pi, ci;
		cin >> pi >> ci;
		p[i] = pi, c[i] = ci;
		duty[pi - 1] += ci;
		heap.emplace(ci, pi);
	}
	cin >> t;

	for (int i = 0; i < 3; ++i) rest[i] = duty[i];
	ll idx[3] = {0, 1, 2};
	if (l[idx[0]] > l[idx[1]]) swap(idx[0], idx[1]);
	if (l[idx[1]] > l[idx[2]]) swap(idx[1], idx[2]);
	if (l[idx[0]] > l[idx[1]]) swap(idx[0], idx[1]);
	ll sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += duty[idx[i]];
		if (l[idx[i]] < sum) {
			cout << "NO\n";
			return;
		}
	}

	ll pass_time = 0, penalty = 0, i = 0;
	vector<pll> temp{};
	while (!heap.empty() || !temp.empty() || i < 3) {
		if (rest[idx[i]] == 0) {
			i++;
			ll len = temp.size();
			if (len > 0) {
				for (int j = 0; j < len; ++j) heap.emplace(temp[j]);
				vector<pll> emp{};
				temp.swap(emp);
			}
			continue;
		}
		auto [ci, pi] = heap.top();
		heap.pop();
		if (pi - 1 != idx[i] && pass_time + ci + rest[idx[i]] > l[idx[i]]) {
			temp.push_back({ci, pi});
			continue;
		}
		if (i == 0 && pi - 1 == idx[i + 2] && pass_time + ci + rest[idx[0]] + rest[idx[1]] > l[idx[1]]) {
			temp.push_back({ci, pi});
			continue;
		}
		rest[pi - 1] -= ci;
		pass_time += ci;
		penalty += pass_time;
	}

	cout << (penalty < t ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) solve();
}

/*
7
3 100 150 175
1 100
2 25
3 50
401
5 100 200 300
1 30
1 30
1 40
2 110
3 50
1275

1 100 300 300
1 300
300

5 20 30 35
2 5
3 5
1 10
2 10
3 5
100

5 20 30 35
2 5
3 5
1 10
2 10
3 5
101

5 35 30 20
2 5
1 5
3 10
2 10
1 5
100

5 35 20 30
2 5
1 5
2 10
3 10
1 5
101


YES
NO
NO
NO
YES
NO
YES

*/
