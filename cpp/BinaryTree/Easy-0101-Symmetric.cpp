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
	bool isSymmetric(TreeNode* root)
	{
		return rec(root->left, root->right);
	}

	bool rec(TreeNode* lhs, TreeNode* rhs)
	{
		if (lhs == nullptr || rhs == nullptr)
		{
			if (lhs == rhs)
				return true;
			else
				return false;
		}
		
		return lhs->val == rhs->val && rec(lhs->right, rhs->left) && rec(lhs->left, rhs->right);
	}
};