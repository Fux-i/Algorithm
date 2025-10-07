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
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		if (!root) return nullptr;
		if (root->val > key) {
			root->left = deleteNode(root->left, key);
			return root;
		}
		if (root->val < key) {
			root->right = deleteNode(root->right, key);
			return root;
		}
		
		// found key:
		auto rightNode = root->right;
		auto leftNode = root->left;
		if (!rightNode && !leftNode)
			return nullptr;
		if (!rightNode)
			return leftNode;
		if (!leftNode)
			return rightNode;
		
		// both exist
		auto temp = rightNode->left;
		rightNode->left = leftNode;
		if (temp)	// 右子树的左子树存在，作为leftNode的右下角叶子节点
		{
			auto node = leftNode;
			while (node->right) node = node->right;	// 获取左子树右下角叶子节点
			node->right = temp;
		}
		return rightNode;
	}
};