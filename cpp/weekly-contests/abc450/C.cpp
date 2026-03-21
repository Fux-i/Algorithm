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
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

#define fi first
#define se second
#define all(a) a.begin(), a.end()
inline void print(pll x){pt(x.fi), putchar(' '), pt(x.se), putchar('\n');}
inline void print(vector<ll> &vec){for(const auto t:vec)pt(t),putchar(' ');puts("");}

ll h, w;
vector<vector<char>> s;
vector<vector<bool>> visited;
ll num = 0;
ll dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
    h = read();
    w = read();
    s.assign(h, vector<char>(w, '#'));
    visited.assign(h, vector<bool>(w, false));
    for (ll i = 0; i < h; ++i)
        for (ll j = 0; j < w; ++j)
            cin >> s[i][j];
}

void dfs(ll i, ll j) {
    if (i < 0 || i >= h || j < 0 || j >= w || visited[i][j]) return;
    visited[i][j] = true;
    if (s[i][j] == '.')
        for (auto &dir : dirs)
            dfs(i + dir[0], j + dir[1]);
}

void solve() {
    for (ll i = 0; i < w; ++i) {
        dfs(0, i);
        dfs(h - 1, i);
    }
    for (ll i = 1; i < h - 1; ++i) {
        dfs(i, 0);
        dfs(i, w - 1);
    }
    //
    for (ll i = 1; i < h - 1; ++i) {
        for (ll j = 1; j < w - 1; ++j) {
            if (!visited[i][j]) {
                if (s[i][j] == '.') {
                    num++;
                    dfs(i, j);
                } else visited[i][j] = true;
            }
        }
    }
}


int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    solve();
    print(num);
}
