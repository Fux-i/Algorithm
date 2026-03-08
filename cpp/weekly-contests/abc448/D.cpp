#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll n;
vector<ll> a;
vector<vector<ll>> g;
vector<bool> result;

void init() {
	n = read();
	a.assign(n + 1, 0);
	for (ll i = 1; i <= n; ++i) {
		a[i] = read();
	}
	g.assign(n + 1, {});
	for (ll i = 1; i < n; ++i) {
		ll u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	result.assign(n + 1, false);
}

unordered_map<ll, ll> cnt;
void dfs(ll node, ll prev, bool already = false) {
	ll new_cnt = ++cnt[a[node]];
	if (already || new_cnt > 1) {
		result[node] = true;
		already = true;
	}
	for (ll child : g[node]) {
		if (child == prev) continue;
		dfs(child, node, already);
	}
	new_cnt = --cnt[a[node]];
	if (new_cnt == 0) cnt.erase(a[node]);
}

void solve() {
	dfs(1, 0);
}

int main() {
	init();
	solve();
	for (ll i = 1; i <= n; ++i) {
		if (result[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
