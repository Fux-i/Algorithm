#include <algorithm>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution
{
public:
	int rob(TreeNode* root)
	{
		auto dfsFunc = [&](this auto&& dfs, TreeNode* node) -> pair<int, int>
		{
			if (!node)
				return {0, 0}; // {偷, 不偷}
			
			auto [leftStolen, leftNot] = dfs(node->left);
			auto [rightStolen, rightNot] = dfs(node->right);

			int stolen = node->val + leftNot + rightNot;
			int notStolen = max(leftStolen, leftNot) + max(rightStolen, rightNot);

			return {stolen, notStolen};
		};

		auto [stolen, notStolen] = dfsFunc(root);
		return max(stolen, notStolen);
	}
};