struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

#include <unordered_set>

class Solution
{
public:
	// 哈希表，时间少，空间多
	// ListNode* detectCycle(ListNode* head)
	// {
	// 	std::unordered_set<ListNode*> set{};
	// 	ListNode* node = head;
	// 	while (node != nullptr)
	// 	{
	// 		if (set.find(node) != set.end())
	// 		{
	// 			return node;
	// 		}
	// 		set.insert(node);
	// 		node = node->next;
	// 	}
	// 	return nullptr;
	// }

	// 快慢指针，数学计算可得，快慢指针相遇时，再来个从头开始的 ptr，它与 slow 距离环入口相等
	ListNode* detectCycle(ListNode* head)
	{
		ListNode *slow = head, *fast = head;
		while (fast != nullptr)
		{
			slow = slow->next;
			if (fast->next == nullptr)
			{
				return nullptr;
			}
			fast = fast->next->next;
			if (fast == slow)
			{
				ListNode* ptr = head;
				while (ptr != slow)
				{
					ptr = ptr->next;
					slow = slow->next;
				}
				return ptr;
			}
		}
		return nullptr;
	}
};