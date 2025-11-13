#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<std::vector<int> > result;
        for (int i = 0; i < n - 2; i++) {
            int num1 = nums[i];
            if (num1 > 0) break; // 最小的数都大于0了
            if (i > 0 && num1 == nums[i - 1]) continue; // 防重复

            int target = -num1;
            int third = n-1;
            for (int j = i + 1; j < n - 1; j++) {
                int num2 = nums[j];
                if (j - i > 1 && num2 == nums[j - 1]) continue; // 防重复

                // 移动第三个指针
                while (third > j && num2 + nums[third] > target) third--;
                if (third == j) continue;
                if (num2 + nums[third] == target) {
                    result.push_back({num1, num2, nums[third]});
                }
            }
        }
        return result;
    }
};
