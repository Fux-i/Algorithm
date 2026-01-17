#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> heap{};
        for (int i = 0; i < k; ++i)
            heap.emplace(nums[i]);
        for (int i = k; i < n; ++i) {
            int val = nums[i];
            if (val <= heap.top()) continue;
            heap.pop();
            heap.emplace(val);
        }
        return heap.top();
    }
};