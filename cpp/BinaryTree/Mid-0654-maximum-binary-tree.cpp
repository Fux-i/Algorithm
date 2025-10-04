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
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
	{
		using vec = std::vector<int>;
		auto it = std::max_element(nums.begin(), nums.end());
		auto node = new TreeNode(*it);
		if (nums.begin() < it)
		{
			vec leftNums(nums.begin(), it);
			node->left = constructMaximumBinaryTree(leftNums);
		}
		if (it < nums.end() - 1)
		{
			vec rightNums(it + 1, nums.end());
			node->right = constructMaximumBinaryTree(rightNums);
		}
		return node;
	}
};