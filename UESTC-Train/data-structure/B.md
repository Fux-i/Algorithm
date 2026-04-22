# 树上数颜色

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
		add(node, -1);
		color_sum = 0;
		max_cnt = 0;
	}
}
```

add 函数也要注意，递归累计颜色数量时要调过重儿子，但清除时不能跳过，否则会影响`node`同级的其他子树

```c++
void add(int node, int val, int h_son = 0) {
	int new_cnt = cnt[color[node]] + val;
	cnt[color[node]] = new_cnt;
	if (new_cnt > max_cnt) {
		max_cnt = new_cnt;
		color_sum = color[node];
	} else if (new_cnt == max_cnt) {
		color_sum += color[node];
	}
	for (int i = head[node]; i; i = nxt[i]) {
		if (to[i] == h_son) continue;
		add(to[i], val);
	}
}
```
