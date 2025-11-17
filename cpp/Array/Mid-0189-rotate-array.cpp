#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> t{};
        for (int i = 0; i < k; i++) {
            int temp = nums.back();
            nums.pop_back();
            t.push_back(temp);
        }
        nums.insert(nums.begin(), t.rbegin(), t.rend());
    }
};
