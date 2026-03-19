//sim
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

using ll = long long;
using ull = unsigned long long;
using db = long double;
typedef long double db;
typedef pair<long long,long long> PLL;
typedef tuple<ll,ll,ll> TLLL;
constexpr ll INF = (ll)2e18+9;
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
constexpr db PI = 3.14159265358979323;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

void init(){

}

void solve() {
    ll N = read();
    ll D = read();
    vector<ll> A(N);
    vector<ll> B(N);
    for (ll i = 0; i < N; ++i) A[i] = read();
    for (ll i = 0; i < N; ++i) B[i] = read();
    ll a = 0, b = 0;
    deque<PLL> q{};
    for (ll i = 0; i < N; ++i) {
        q.emplace_back(i, A[i]);

        ll use = B[i];
        while (use > 0) {
            ll rem = q.front().second;
            if (rem > use) {
                q.front().second -= use;
                break;
            } else if (rem == use) {
                q.pop_front();
                break;
            } else {
                q.pop_front();
                use -= rem;
            }
        }

        for (PLL& p : q) {
            if (p.first <= i - D) q.pop_front();
            else break;
        }
    }
    ll sum = 0;
    for (PLL& p : q) {
        sum += p.second;
    }
    print(sum);
}


int main() {
    init();
    ll t = 1;
    t = read();
    while (t--) {
        solve();
    }
}
