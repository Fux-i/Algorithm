//dp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll n;
vector<ll> a;

void init() {
    n = read();
    a.assign(n, 0);
    for (ll i = 0; i < n; i++) {
        a[i] = read();
    }
}

void solve() {
    vector<ll> precnt(n);
    vector<vector<ll> > idxs(n+1);
    vector<ll> dp(n);       // dp[i]: number of ways that ends at index i
    vector<ll> acc(n+1);    // acc[i]: sum accumulated from dp[0] to dp[i-1]
    acc[0] = 0;
    for (ll i = 0; i < n; i++) {
        precnt[i] = idxs[a[i]].size();
        idxs[a[i]].push_back(i);
    }
    for (ll i = 0; i < n; i++) {
        ll val;

        if (precnt[i] < a[i] - 1) val = 0;
        else if (precnt[i] == a[i] - 1) val = acc[idxs[a[i]][0]] - acc[0] + 1;
        else val = acc[idxs[a[i]][precnt[i] - a[i] + 1]] - acc[idxs[a[i]][precnt[i] - a[i] + 0] + 1];

        dp[i] = (val + MOD) % MOD;
        acc[i+1] = (acc[i] + dp[i]) % MOD;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) ans += dp[i];
    ans %= MOD;
    print(ans);
}

int main() {
    init();
    solve();
}