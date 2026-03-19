#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

int main() {
	ll n = read();
	vector<ll> v(n + 1);
	vector<ll> ans(n + 1);
	for (ll i = 1; i <= n; i++) {
		v[i] = read();
	}
	auto find = [&](auto &&find, ll x) -> ll {
		return  x == v[x] ? x : v[x] = find(find, v[x]);
	};
	for (ll i = n; i > 0; i--) {
		ans[i] = find(find, i);
	}
	for (ll i = 1; i <= n; i++) {
		pt(ans[i]);
		putchar(' ');
	}
}
