#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(nums, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(nums[i], nums[0]);
            Heapify(nums, i, 0);
        }
        return nums;
    }

    void Heapify(vector<int> &nums, int n, int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = left + 1;
            int largest = i;
            if (left < n && nums[left] > nums[largest])
                largest = left;
            if (right < n && nums[right] > nums[largest])
                largest = right;
            if (largest == i)
                return;
            swap(nums[i], nums[largest]);
            i = largest;
        }
    }
};
