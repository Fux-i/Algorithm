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
	std::vector<int> postorderTraversal(TreeNode* root)
	{
		std::vector<int> ret;
		std::stack<std::pair<TreeNode*, bool>> stk;	// bool 表示是否标记过
		
		stk.emplace(root, false);
		while (!stk.empty())
		{
			auto [node, flag] = stk.top();
			stk.pop();
			if (node == nullptr)
				continue;
			if (flag == false)
			{
				stk.emplace(node, true);
				stk.emplace(node->right, false);
				stk.emplace(node->left, false);
			}
			else
			{
				ret.push_back(node->val);
			}
		}

		return ret;
	}
};