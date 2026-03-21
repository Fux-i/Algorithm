#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using db = long double;
constexpr ll INF = (ll)2e18+9;
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr db PI = 3.14159265358979323;

// io functions
// ios::sync_with_stdio(false); cin.tie(nullptr);
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

#define fi first
#define se second
#define all(a) a.begin(), a.end()
inline void print(pll x){pt(x.fi), putchar(' '), pt(x.se), putchar('\n');}
inline void print(vector<ll> &vec){for(const auto t:vec)pt(t),putchar(' ');puts("");}

int main() {
    ll n = read(), k = read();
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    	a[i] = read() % k;
    ranges::sort(a);

	ll max_gap = 0;
	for (ll i = 1; i < n; ++i)
		max_gap = max(max_gap, a[i] - a[i - 1]);
	max_gap = max(max_gap, a[0] + k - a[n - 1]);
	print(k - max_gap);
}
