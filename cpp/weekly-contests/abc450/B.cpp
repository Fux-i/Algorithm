#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// io functions
// ios::sync_with_stdio(false); cin.tie(nullptr);
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}

int main() {
    ll n = read();
    vector<vector<ll>> c(n+1, vector<ll>(n+1, 0));
    for (ll i = 1; i < n; ++i)
        for (ll j = i+1; j <= n; ++j)
        	c[i][j] = read();
	bool yes = false;
	for (ll i = 1; i < n - 1; ++i)
		for (ll j = i+1; j < n; ++j)
			for (ll k = j+1; k <= n; ++k)
				if (c[i][j] + c[j][k] < c[i][k]) {
					yes = true;
					goto B;
				}

B:  cout << (yes ? "Yes" : "No");
}
