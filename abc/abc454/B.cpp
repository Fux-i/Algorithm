#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool q1 = true, q2 = false;
    ll n, m; cin >> n >> m;
    unordered_map<ll, ll> table{};
    for (ll i = 0; i < n; ++i) {
        ll type; cin >> type;
        if (++table[type] == 2) q1 = false;
        if (table.size() >= m) q2 = true;
    }
    cout << (q1 ? "Yes\n" : "No\n") << (q2 ? "Yes\n" : "No\n");
}
