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
	int lastVal = INT32_MIN;
	bool isBST = true;
	bool isFirstTime = true;
public:
	bool isValidBST(TreeNode* root)
	{
		dfs(root);
		return isBST;
	}

	void dfs(TreeNode* node)
	{
		if (!node)
			return;
		dfs(node->left);
		if (isFirstTime)
			isFirstTime = false;
		else if (node->val <= lastVal)
		{
			isBST = false;
			return;
		}
		lastVal = node->val;
		dfs(node->right);
	}
};