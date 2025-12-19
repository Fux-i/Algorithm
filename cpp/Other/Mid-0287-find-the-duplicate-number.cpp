#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        bitset<100001> set{};
        for (int &num: nums) {
            if (set[num]) {
                return num;
            }
            set[num] = true;
        }
        return 0;
    }
};

/*
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};*/
