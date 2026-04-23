# UESTC 暑假前集训 - 数据结构专题

## A.月光

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

## B.树上数颜色

看这题第一眼想法就是树形 DP，开个`<node, color>`的二维数组，递归统计以`node`为根的子树的所有颜色数量，
虽然时间空间都超了，但也没有其他思路了，只能先硬着头皮试一试，结果不出意外 MLE 了。

好吧，只能去学一下能高效做子树查询的数据结构了，也就是 dsu on tree 的这么个东西。
相比之前的朴素解法，该算法的高明之处在于：

1. 用单个全局变量`cnt[maxn]`（$O(n$)）来保存所有颜色数量，而不用维护$O(n^2)$的二维数组
2. 为了避免试用全局变量时不同子树互相干扰的问题，区分重儿子和轻儿子，先遍历所有轻儿子取得结果后清除对`cnt[maxn]`的影响，
   把重儿子留到最后，保留影响。这样每个节点就最多被计算$logn$次，因此时间复杂度可以降到$nlogn$

回到代码，首先是基础的数据读入，这里用链式前向星来存树，由于是有根树，就不用当做无向边存两遍了

```c++
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		to[i] = v;
		nxt[i] = head[u];
		head[u] = i;
	}
	dfs1(1);
	dfs2(1, true);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
	}
}
```

其中 dfs1 是用来找重儿子的

```c++
void dfs1(int node) {
	int max_size = 0;
	siz[node] = 1;
	for (int i = head[node]; i; i = nxt[i]) {
		dfs1(to[i]);
		int child_size = siz[to[i]];
		siz[node] += child_size;
		if (child_size > max_size) {
			max_size = child_size;
			son[node] = to[i];
		}
	}
}
```

dfs2 才是真正开始计算，因为需要 dfs1 结束后才知道谁是重儿子，才知道以什么顺序来计算。

这里需要注意处理重儿子时要保留影响，参数`clear`为`false`

```c++
void dfs2(int node, bool clear) {
	int h_son = son[node];
	for (int i = head[node]; i; i = nxt[i]) {
		if (to[i] == h_son) continue;
		dfs2(to[i], true);
	}
	if (h_son) {
		dfs2(h_son, false);
	}
	add(node, 1, h_son);
	ans[node] = color_sum;
	if (clear) {
		add(node, -1);  // 清除时要清除重儿子在内的所有累计
		color_sum = 0;
		max_cnt = 0;
	}
}
```

add 函数也要注意，递归累计颜色数量时要调过重儿子，但清除时不能跳过，否则会影响`node`同级的其他子树

```c++
void add(int node, int val, int h_son = 0) {
	...
	for (int i = head[node]; i; i = nxt[i]) {
		if (to[i] == h_son) continue;
		add(to[i], val);
	}
}
```

## D.线段树全家桶

额额很好的线段树全家桶，线段树是一种可以在$O(logn)$时间复杂度内实现区间修改、查询操作的高效数据结构。
本质上是二叉树，每个叶子节点对应数组中的单个值，非叶子节点则对应$[l, r]$区间中的信息（区间和、最大值等），一开始我疑惑这里的`l`和`r`是怎么来的呢？
多用了几次才领悟到这就是线段树的精髓所在，`l`和`r`不会直接给出，而是**必须**每次查询/修改时一路递归演变下来，顺带把该计算的都计算了，
不需要存在节点中。

在做实现区间修改时，为了避免递归到叶子节点，可以用到懒标记，等查询到这个节点时，再做更新。我的代码中线段树节点定义如下：

```c++
 struct Node {
     ll val = 0;    // 区间和
     ll max = 0;    // 区间最大值
     ll mul = 1;
     ll add = 0;
 };
```

这里用`mul`和`add`两个值来作为懒标记，处理逻辑需要仔细琢磨...尤其是处理`val`和`add`本身时，要考虑区间覆盖的范围，加`add * (r - l + 1)`

`apply`实现如下：

```c++
 void apply(ll idx, ll l, ll r, ll mul, ll add) {
     Node &o = tree[idx];
     o = {
         o.val * mul + add * (r - l + 1),
         o.max * mul + add,
         o.mul * mul,
         o.add * mul + add
     };
 }
```

所以 range assign 时只需`tree[idx] = {ass * (r - l + 1), ass, 0, ass};`就好了，assign 会直接覆盖原有的未处理的`mul`和`add`。
