#include <algorithm>
#include <stdint.h>

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
	int lastVal = 0;
	int minDiff = INT32_MAX;
	bool isFirstTime = true;
public:
	int getMinimumDifference(TreeNode* root)
	{
		dfs(root);
		return minDiff;
	}

	void dfs(TreeNode* node)
	{
		if (!node)
			return;
		dfs(node->left);
		if (isFirstTime)
			isFirstTime = false;
		else
			minDiff = std::min(minDiff, node->val - lastVal);
		lastVal = node->val;
		dfs(node->right);
	}
};