#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n + 1, vector<ll>());
    for (ll i = 0; i < m; ++i) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    vector<ll> visited(n + 1);
    ll ans = 0;
    auto dfs = [&](auto&& dfs, ll node) {
        if (visited[node]) return;
        visited[node] = true;
        ans++;
        for (auto& next : g[node]) {
            dfs(dfs, next);
        }
    };
    dfs(dfs, 1);
    cout << ans << '\n';
}
