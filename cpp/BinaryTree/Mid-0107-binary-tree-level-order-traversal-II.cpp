#include <queue>
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
	std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
	{
		std::vector<std::vector<int>> ret{};

		int level = -1;

		std::queue<TreeNode*> qu;
		qu.push(nullptr);
		if (root != nullptr)
			qu.push(root);

		while (!qu.empty())
		{
			auto node = qu.front();
			qu.pop();
			// 为空，新 level 标记
			if (node == nullptr)
			{
				// 队列为空说明无有效节点了
				if (qu.empty())
					break;
				level++;
				qu.push(nullptr);

				std::vector<int> newVec{};
				ret.push_back(newVec);
				continue;
			}

			// 不为空，将其加入 ret，子节点加入 queue
			ret[level].push_back(node->val);
			if (node->left != nullptr)
				qu.push(node->left);
			if (node->right != nullptr)
				qu.push(node->right);
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
};