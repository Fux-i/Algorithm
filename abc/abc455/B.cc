#include <bits/stdc++.h>

#define grid dp[i][j][x][y]

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

char g[10][10];
bool dp[10][10][10][10];

bool check(ll i, ll j, ll x, ll y) {
	ll h = x - i, w = y - j;
	for (ll a = 0; a <= h; a++)
		if (g[i+a][j] != g[x-a][y]) return false;
	for (ll a = 0; a <= w; a++)
		if (g[i][j+a] != g[x][y-a]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll h, w;
	cin >> h >> w;
	for (ll i = 0; i < h; ++i) {
		string line;
		cin >> line;
		for (ll j = 0; j < w; ++j) g[i][j] = line[j];
	}
	ll ans = 0;
	for (ll a = 0; a < h; ++a)
		for (ll b = 0; b < w; ++b)
			for (ll i = 0; i + a < h; ++i)
				for (ll j = 0; j + b < w; ++j) {
					ll x = i + a, y = j + b;
					bool res = check(i, j, x, y);
					if (a > 1 && b > 1) res = res && dp[i+1][j+1][x-1][y-1];
					grid = res;
					if (res) ans++;
				}
	cout << ans;
}

/*


*/