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
	int sum = 0;
	std::vector<std::vector<int>> paths;
	std::vector<int> path;
	int target = 0;
public:
	std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
	{
		target = targetSum;
		dfs(root);
		return paths;
	}

	void dfs(TreeNode* root)
	{
		if (!root)
			return;
		
		int value = root->val;
		sum += value;
		path.push_back(value);
		
		if (sum == target && !root->left && !root->right)
		{
			paths.push_back(path);
			sum -= value;
			path.pop_back();
			return;
		}

		dfs(root->left);
		dfs(root->right);
		
		sum -= value;
		path.pop_back();
	}
};