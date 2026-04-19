#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string process(string &s) {
	ll len = s.length();
	string ans(len, '\0');
	ll l = 0, idx = 0, p = 0;
	bool can = false;
	for (ll i = 0; i < len; ++i) {
		if (s[i] == '(') {
			if (p > 0) {
				idx -= 2 * p + 2;
				l = 0;
				ans[idx++] = 'x';
				ans[idx++] = 'x';
			}
			can = false;
			l++;
			ans[idx++] = '(';
		} else if (s[i] == 'x') {
			if (p > 0) {
				idx -= 2 * p + 2;
				l = 0;
				ans[idx++] = 'x';
				ans[idx++] = 'x';
			}
			if (i > 0 && s[i - 1] == 'x' && l > 0) can = true;
			ans[idx++] = 'x';
		} else {
			if (!can) {
				ans[idx++] = ')';
			} else {
				p++;
				ans[idx++] = ')';
				if (l == p) {
					idx -= 2 * p + 2;
					l = 0;
					ans[idx++] = 'x';
					ans[idx++] = 'x';
					can = false;
				}
			}
		}
	}
	ans = ans.substr(0, idx);
	cout << ans << '\n';
	return ans;
}

string process2(string &s) {
	ll len = s.length();
	string ans(len, '\0');
	ll idx = 0;
	for (ll i = 0; i < len; ++i) {
		ans[idx++] = s[i];
		if (s[i] == ')' && idx >= 4 && ans.substr(idx - 4, 4) == "(xx)") {
			idx -= 4;
			ans[idx++] = 'x';
			ans[idx++] = 'x';
		}
	}
	ans = ans.substr(0, idx);
	// cout << ans << '\n';
	return ans;
}

void solve() {
	string A, B;
	cin >> A >> B;
	string pa = process2(A), pb = process2(B);
	cout << (pa == pb ? "Yes\n" : "No\n");
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
6
(xx)x
x(xx)
(x)x
(xx)
)x()x(
)x()x(
x
(x)
(((((xx)))))x
x((((((((((xx))))))))))
((xx)xx)xx
(x((xx))x)(xx)

*/