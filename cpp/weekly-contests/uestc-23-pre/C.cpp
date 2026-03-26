#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}

void solve() {
    ll n = read(), m = read();
    string s(n, '*');
    while (m--) {
        ll p = read() - 1, l = read();
        string patch = ">" + string(l - 4, '-') + ">>>";
        string new_s = s.substr(0, p).append(patch).append(s.substr(p + l));
        swap(s, new_s);
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll t = 1;
    t = read();
    while (t--) {
        solve();
    }
}
