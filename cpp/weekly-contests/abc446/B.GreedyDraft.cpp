//greedy
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll N, M;
bitset<101> s{};

void init(){

}

void solve() {
    ll l = read();
    while (l--) {
        ll j = read();
        if (!s[j]) {
            s[j] = true;
            print(j);
            while (l--) ll t = read();
            return;
        }
    }
    print(0);
}


int main() {
    init();
    N = read();
    M = read();
    while (N--) {
        solve();
    }
}
