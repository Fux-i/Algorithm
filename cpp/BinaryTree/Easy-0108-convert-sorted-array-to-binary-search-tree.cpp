#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode* sortedArrayToBST(std::vector<int>& nums)
	{
		int l = 0;
		int r = nums.size() - 1;
		return rec(nums, l, r);
	}

	TreeNode* rec(std::vector<int>& nums, int l, int r)
	{
		if (l > r) return nullptr;
		int mid = (l + r) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = rec(nums, l, mid-1);
		node->right = rec(nums, mid+1, r);
		return node;
	}
};