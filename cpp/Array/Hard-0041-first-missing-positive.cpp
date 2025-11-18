#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        size_t size = nums.size();
        for (int i = 0; i < size; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] >= size || nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size + 1;
    }
};