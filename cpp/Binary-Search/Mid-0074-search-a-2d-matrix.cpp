#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;

        int row = -1;
        while (matrix[++row][m-1] < target);
        auto nums = matrix[row];
        if (nums[m-1] == target || nums[0] == target) return true;

        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return false;
    }
};