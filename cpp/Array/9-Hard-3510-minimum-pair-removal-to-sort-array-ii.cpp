#include <queue>
#include <vector>
#include <bits/ranges_algo.h>
using namespace std;

class Solution {
public:
	int minimumPairRemoval(vector<int> &nums) {
		int n = nums.size();
		priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<> > pq; // (相邻元素和，左边那个数的下标)
		int dec = 0; // 递减的相邻对的个数
		for (int i = 0; i + 1 < n; i++) {
			int x = nums[i], y = nums[i + 1];
			if (x > y) {
				dec++;
			}
			pq.emplace(x + y, i);
		}

		// 每个下标的左右最近的未删除下标
		vector<int> left(n + 1), right(n);
		ranges::iota(left, -1);
		ranges::iota(right, 1);

		vector<long long> a(nums.begin(), nums.end());
		int ans = 0;
		while (dec) {
			ans++;

			// 如果堆顶数据与实际数据不符，说明堆顶数据是之前本应删除，但没有删除的数据（懒删除）
			while (right[pq.top().second] >= n || pq.top().first != a[pq.top().second] + a[right[pq.top().second]]) {
				pq.pop();
			}
			auto [s, i] = pq.top();
			pq.pop(); // 删除相邻元素和最小的一对

			// (当前元素，下一个数)
			int nxt = right[i];
			dec -= a[i] > a[nxt]; // 旧数据

			// (前一个数，当前元素)
			int pre = left[i];
			if (pre >= 0) {
				dec -= a[pre] > a[i]; // 旧数据
				dec += a[pre] > s; // 新数据
				pq.emplace(a[pre] + s, pre);
			}

			// (下一个数，下下一个数)
			int nxt2 = right[nxt];
			if (nxt2 < n) {
				dec -= a[nxt] > a[nxt2]; // 旧数据
				dec += s > a[nxt2]; // 新数据（当前元素，下下一个数）
				pq.emplace(s + a[nxt2], i);
			}

			a[i] = s;
			// 删除 nxt
			int l = left[nxt], r = right[nxt];
			right[l] = r; // 模拟双向链表的删除操作
			left[r] = l;
			right[nxt] = n; // 表示删除 nxt
		}

		return ans;
	}
};
