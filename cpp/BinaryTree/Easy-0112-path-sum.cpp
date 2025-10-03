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
	int sum = 0;
public:
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (!root)
			return false;
		
		int value = root->val;
		sum += value;
		if (sum == targetSum && !root->left && !root->right)
			return true;

		if (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum))
			return true;
		
		sum -= value;
		return false;
	}
};