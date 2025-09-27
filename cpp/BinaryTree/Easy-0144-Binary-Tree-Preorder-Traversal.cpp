#include <queue>
#include <stack>
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
	std::vector<int> preorderTraversal(TreeNode* root)
	{
		std::vector<int> ret;
		std::stack<TreeNode*> stk;
		TreeNode* node = root;
		while (!stk.empty() || node != nullptr)
		{
			while (node != nullptr)
			{
				ret.emplace_back(node->val);
				stk.emplace(node);
				node = node->left;
			}
			node = stk.top();
			stk.pop();
			node = node->right;
		}

		return ret;
	}

	// void rec(TreeNode* node, std::vector<int>& v)
	// {
	// 	if (!node)
	// 		return;
	// 	v.push_back(node->val);
	// 	rec(node->left, v);
	// 	rec(node->right, v);
	// }
};