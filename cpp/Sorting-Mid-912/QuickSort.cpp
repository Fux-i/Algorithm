#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = partition(nums, l, r);
        quickSort(nums, l, mid - 1);
        quickSort(nums, mid + 1, r);
    }

    int partition(vector<int> &nums, int l, int r) {
        int i = l + rand() % (r - l + 1);
        int target = nums[i];
        swap(nums[l], nums[i]);
        int p = l;
        while (l < r) {
            while (l < r && target <= nums[r])
                r--;
            while (l < r && target >= nums[l])
                l++;
            swap(nums[l], nums[r]);
        }
        swap(nums[l], nums[p]);
        return l;
    }
};
