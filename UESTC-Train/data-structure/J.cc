#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6 + 2;
int n, a[maxn], lb[maxn], rb[maxn], best[maxn];
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		lb[i] = s.empty() ? 0 : s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();
	for (int i = n; i >= 1; --i) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		rb[i] = s.empty() ? n + 1 : s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		int len = rb[i] - lb[i] - 1;
		best[len] = max(best[len], a[i]);
	}
	for (int i = n - 1; i >= 1; --i) best[i] = max(best[i], best[i + 1]);

	string ans;
	ans.reserve(n);
	for (int i = 1; i <= n; ++i) {
		int b; cin >> b;
		ans.push_back(best[i] >= b ? '1' : '0');
	}
	cout << ans;
}

/*
5
1 3 2 5 3
6 3 3 2 3

*/