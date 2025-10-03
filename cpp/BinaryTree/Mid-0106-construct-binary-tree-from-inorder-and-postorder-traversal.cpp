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
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
	{
		int value = postorder.back();
		auto node = new TreeNode(value);
		auto it = std::find(inorder.begin(), inorder.end(), value);
		// 切分子树
		ptrdiff_t leftSize = 0;
		if (inorder.begin() < it)
		{
			leftSize = it - inorder.begin();
			std::vector<int> inLeft(inorder.begin(), it);
			std::vector<int> postLeft(postorder.begin(), postorder.begin() + leftSize);
			node->left = buildTree(inLeft, postLeft);
		}
		if (it < inorder.end() - 1)
		{
			std::vector<int> inRight(it + 1, inorder.end());
			std::vector<int> postRight(postorder.begin() + leftSize, postorder.end() - 1);
			node->right = buildTree(inRight, postRight);
		}
		return node;
	}
};