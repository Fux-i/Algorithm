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
	int minCameraCover(TreeNode* root)
	{
		bool camera, covered;
		int ans = dfs(root, camera, covered);
		if (!covered)
			ans++;
		return ans;
	}

	int dfs(TreeNode* root, bool& camera, bool& covered)
	{
		if (!root)
		{
			camera = false;
			covered = true;
			return 0;
		}

		bool left_covered;
		bool right_covered;
		bool left_camera;
		bool right_camera;
		int num_left_camera = dfs(root->left, left_camera, left_covered);
		int num_right_camera = dfs(root->right, right_camera, right_covered);


		if (!left_covered || !right_covered)
		{
			camera = true;
			covered = true;
			return num_left_camera + num_right_camera + 1;
		}
		if (left_camera || right_camera)
		{
			camera = false;
			covered = true;
			return num_left_camera + num_right_camera;
		}
		camera = false;
		covered = false;
		return num_left_camera + num_right_camera;
	}
};