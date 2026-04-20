# A-月光

题目可转化为：有 n 个普通节点（1~n），与上界下界两个特殊节点（0，n+1），求两特殊节点是否连通，显然可以用并查集。

带启发式合并的并查集：

```c++
vector<ll> dsu, sizes;

ll find(ll x) {
	return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void unite(ll x, ll y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sizes[x] < sizes[y]) swap(x, y);
	dsu[y] = x;
	sizes[x] += sizes[y];
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}
```

数据读入后执行两个带早退的大循环。

第一个是判断普通节点与特殊节点是否连通，比较 y 方向的距离与半径即可

```c++
for (ll i = 1; i <= n; ++i) {
    circle &c = cs[i];
    if (abs(c.y - y11) <= c.r) unite(i, 0);
    if (abs(c.y - y22) <= c.r) unite(i, n + 1);
    if (same(0, n + 1)) {
        cout << "Yes\n";
        return 0;
    }
}
```

第二个是普通节点之间两两判断是否连通，比较圆心距离与半径之和

```c++
for (ll i = 1; i < n; ++i) {
    for (ll j = 1; i + j <= n; ++j) {
        auto &c1 = cs[i], c2 = cs[i + j];
        if (check(c1, c2)) unite(i, i + j);
        if (same(0, n + 1)) {
            cout << "Yes\n";
            return 0;
        }
    }
}
```
