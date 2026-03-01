//disjoint set
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

using ll = long long;
using pll = pair<ll, ll>;
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

//fast pow
ll ksm(ll a, ll b=MOD-2, ll M=MOD){a%=M;ll res=1;while(b){if(b&1){res=(res*a)%M;}a=(a*a)%M;b>>=1;}return res;}

class dsu {
	std::vector<size_t> parents, sizes;

public:
	explicit dsu(const size_t size) : parents(size + 1), sizes(size + 1, 1) {
		std::iota(parents.begin(), parents.end(), 0);
	}

	size_t find(const size_t x) {
		return parents[x] == x ? x : parents[x] = find(parents[x]);
	}

	bool same(const size_t x, const size_t y) {
		return find(x) == find(y);
	}

	void unite(size_t x, size_t y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sizes[x] < sizes[y]) std::swap(x, y);
		parents[y] = x;
		sizes[x] += sizes[y];
	}
};

int main() {
	ll n = read(), m = read();
	vector<pll> e(m);
	for (ll i = 0; i < m; ++i) {
		e[i].fi = read();
		e[i].se = read();
	}
	dsu set(n);
	ll cnt = n, ans = 0;
	for (ll i = m - 1; i >= 0; --i) {
		auto& [a, b] = e[i];
		if (!set.same(a, b)) {
			if (cnt > 2) {
				set.unite(a, b);
				cnt--;
			} else {
				ans = (ans + ksm(2, i + 1)) % MOD;
			}
		}
	}
	print(ans);
}
