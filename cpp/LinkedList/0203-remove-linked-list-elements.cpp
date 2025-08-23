struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// class Solution
// {
// public:
// 	ListNode* removeElements(ListNode* head, int val)
// 	{
// 		if (head == nullptr)
// 		{
// 			return head;
// 		}
// 		head->next = removeElements(head->next, val);
// 		return head->val == val ? head->next : head;
// 	}
// };

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == nullptr)
			return head;

		while (head != nullptr && head->val == val)
			head = head->next;

		if (head == nullptr)
			return nullptr;

		ListNode* node = head;
		while (node->next != nullptr)
		{
			if (node->next->val == val)
				node->next = node->next->next;
			else
				node = node->next;
		}
		return head;
	}
};