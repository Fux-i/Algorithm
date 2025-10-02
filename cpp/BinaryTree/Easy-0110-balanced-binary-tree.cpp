#include <algorithm>
#include <cstdlib>

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
	bool isBalanced(TreeNode* root)
	{
		return getBalancedDepth(root) != -1;
	}

	// 返回树的高度，若不是平衡二叉树则返回-1
	int getBalancedDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		int ld = getBalancedDepth(root->left);
		int rd = getBalancedDepth(root->right);
		if (ld == -1 || rd == -1)
			return -1;
		if (abs(ld - rd) > 1)
			return -1;
		return 1 + std::max(ld, rd);
	}
};