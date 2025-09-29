#include <queue>
#include <vector>

class Node {
public:
	int val;
	std::vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, std::vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:
	std::vector<std::vector<int>> levelOrder(Node* root) {
		std::vector<std::vector<int>> ret;
		std::queue<Node*> qu;
		qu.push(nullptr);
		if (root != nullptr)
			qu.push(root);

		short index = -1;

		while (!qu.empty())
		{
			auto node = qu.front();
			qu.pop();
			if (node == nullptr)
			{
				if (qu.empty())
					break;
				index++;
				qu.push(nullptr);
				std::vector<int> v;
				ret.push_back(v);
				continue;
			}

			ret[index].push_back(node->val);
			for (auto child : node->children)
			{
				if (child != nullptr)
					qu.push(child);
			}
		}

		return ret;
	}
};