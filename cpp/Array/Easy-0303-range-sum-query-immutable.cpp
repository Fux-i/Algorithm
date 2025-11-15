#include <vector>
using namespace std;

class NumArray {
    vector<int> pre;

public:
    NumArray(vector<int> &nums) {
        pre.reserve(nums.size());
        int sum = 0;
        for (int num: nums) {
            sum += num;
            pre.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        int preSum = left == 0 ? 0 : pre[left - 1];
        return pre[right] - preSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
