#include <queue>

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
	TreeNode* ans;

	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr)
			return false;
		bool lson = dfs(root->left, p, q);	// 左子树是否包含p或q
		bool rson = dfs(root->right, p, q);	// 右子树是否包含p或q
		if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
			ans = root;
		return lson || rson || (root->val == p->val || root->val == q->val);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		dfs(root, p, q);
		return ans;
	}
};

/* 5%, 5%
class Solution
{
	TreeNode* lastAncestor = nullptr;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		lastAncestor = root;
		if (root->left)
			dfs(root->left, p, q);
		if (root->right)
			dfs(root->right, p, q);
		return lastAncestor;
	}

	void dfs(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!isAncestor(root, p, q))
			return;

		lastAncestor = root;
		if (root->left)
			dfs(root->left, p, q);
		if (root->right)
			dfs(root->right, p, q);
	}

	bool isAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		int found = 0;
		std::queue<TreeNode*> qu;
		qu.push(root);
		while (!qu.empty())
		{
			auto node = qu.front();
			qu.pop();
			if (node == p || node == q)
				found++;
			if (node->left)
				qu.push(node->left);
			if (node->right)
				qu.push(node->right);
		}
		if (found == 2)
			return true;
		return false;
	}
};
*/