//tree dp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

void solve() {
	ll n = read();
	vector<ll> degree(n + 1, 0);
	vector<vector<ll> > g(n + 1, vector<ll>{});
	for (ll i = 0; i < n - 1; ++i) {
		ll a = read(), b = read();
		degree[a]++;
		degree[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	ll ans = 1;
	auto dfs = [&](auto &&dfs, ll node, ll prev = 0) -> ll {
		priority_queue<ll> heap{};
		for (ll v : g[node])
			if (v != prev)
				heap.emplace(dfs(dfs, v, node));

		ll end = 0;
		if (degree[node] > 3) {
			end = 1 + heap.top(); heap.pop();
			ans = max(ans, end + heap.top());
		} else if (degree[node] == 3) {
			end = 1;
			ans = max(ans, end + heap.top());
		}
		return end;
	};

	dfs(dfs, 1);
	print(ans);
}


int main() {
	ll t = 1;
	t = read();
	while (t--) {
		solve();
	}
}
