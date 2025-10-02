#include <algorithm>
#include <cstdlib>
#include <string>
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
	std::vector<std::string> ret;
public:
	std::vector<std::string> binaryTreePaths(TreeNode* root)
	{
		rec(root, "");
		return ret;
	}

	void rec(TreeNode* node, std::string path)
	{
		if (path.empty())
			path.append(std::to_string(node->val));
		else
		{
			path.append(std::string("->"));
			path.append(std::to_string(node->val));
		}
		if (!node->left && !node->right)
			ret.push_back(path);
		else
		{
			if (node->left)
				rec(node->left, path);
			if (node->right)
				rec(node->right, path);
		}
	}
};