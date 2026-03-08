#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

using ll = long long;
using pll = pair<ll, ll>;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll n, q;
vector<pll> a;
vector<bool> removed;

void init() {
	n = read();
	q = read();
	a.assign(n, {});
	removed.assign(n, 0);
	for (ll i = 0; i < n; ++i) {
		a[i].fi = read();
		a[i].se = i;
	}
	sort(all(a), less<>());
}

void solve() {
	removed.assign(n, false);
	ll c = read();
	while (c--) {
		removed[read() - 1] = true;
	}
	for (ll i = 0; i < n; ++i) {
		if (removed[a[i].se]) continue;
		print(a[i].fi);
		break;
	}
}


int main() {
	init();

	while (q--) {
		solve();
	}
}
