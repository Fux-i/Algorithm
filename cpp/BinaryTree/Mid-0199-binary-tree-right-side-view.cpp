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
	std::vector<int> rightSideView(TreeNode* root)
	{
		std::vector<std::vector<int>> levelInfo{};
		std::vector<int> ret{};

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
				levelInfo.push_back(newVec);
				continue;
			}

			// 不为空，将其加入 levelInfo，子节点加入 queue
			levelInfo[level].push_back(node->val);
			if (node->right != nullptr)	// 右节点先入队列，保持最右节点在[0]位置
				qu.push(node->right);
			if (node->left != nullptr)
				qu.push(node->left);
		}

		// 将每层最右侧节点加入 ret
		const size_t size = levelInfo.size();
		ret.reserve(size);
		for (size_t i = 0; i < size; i++)
			ret.emplace_back(levelInfo[i][0]);

		return ret;
	}
};