#include <vector>

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        std::vector<int> v(nums.size());
        int l = 0, r = nums.size() - 1, i = nums.size() - 1;
        while (i >= 0)
        {
            int lv = nums[l] < 0 ? -nums[l] : nums[l];
            int rv = nums[r] < 0 ? -nums[r] : nums[r];
            if (lv < rv)
            {
                v[i] = rv * rv;
                r--;
            }
            else
            {
                v[i] = lv * lv;
                l--;
            }
            i--;
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
    Solution s{};
    std::vector<int> n = {0,1,2,2,3,0,4,2};
    auto a = s.sortedSquares(n);
}
