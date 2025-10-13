#include <algorithm>
#include <vector>

class Solution
{
	size_t size_;
	std::vector<int> nums_;
	std::vector<int> one_;
	std::vector<std::vector<int>> ret;
public:
	std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums)
	{
		size_ = nums.size();
		nums_ = nums;

		backTracing(0);
		return ret;
	}

	void backTracing(size_t idx)
	{
		if (idx == size_)
		{
			if (one_.size() > 1)
				ret.push_back(one_);
			return;
		}

		if (!one_.empty() && nums_[idx] < one_.back())
		{
			backTracing(idx + 1);
			return;
		}

		if (!(idx > 0 && !one_.empty() && one_.back() == nums_[idx]))
			backTracing(idx + 1);

		one_.push_back(nums_[idx]);
		backTracing(idx + 1);
		one_.pop_back();
	}
};