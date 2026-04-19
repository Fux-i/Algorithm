#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	a--;b--;
	if (n % 2 == 1 || (a + b) % 2 == 0) {
		cout << "No\n";
		return;
	}
	string s1, s2;
	for (int i = 0; i < n / 2 - 1; ++i) {
		string s = string(n - 1, 'R') + "D" + string(n - 1, 'L') + "D";
		if (a >= 2) {
			s1.append(s);
			a -= 2;
		} else {
			// ranges::reverse(s);
			s2.append(s);
		}
	}
	for (int i = 0; i < n / 2 - 1; ++i) {
		if (b >= 2) {
			s1.append("DRUR");
			b -= 2;
		} else {
			s2.append("DRUR");
		}
	}
	assert(a == 0 && b == 1 || a == 1 && b == 0);
	if (a == 0 && b == 1) {
		s1.append("DR");
	} else {
		s1.append("RD");
	}
	ranges::reverse(s2);
	cout << "Yes\n" << s1 + s2 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
}

/*
4
2 1 2
3 2 2
4 3 2
6 3 4

*/
