#include <unordered_set>
#include <vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	/* vector用时超5%，内存超8%
	 * unordered_set用时超23%，内存超6%
	 */
	// ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	// {
	// 	std::unordered_set<ListNode *> visited;
	// 	ListNode *temp = headA;
	// 	while (temp != nullptr) {
	// 		visited.insert(temp);
	// 		temp = temp->next;
	// 	}
	// 	temp = headB;
	// 	while (temp != nullptr) {
	// 		if (visited.count(temp)) {
	// 			return temp;
	// 		}
	// 		temp = temp->next;
	// 	}
	// 	return nullptr;
	// }
	// ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	// {
	// 	if (headA == nullptr || headB == nullptr)
	// 	{
	// 		return nullptr;
	// 	}
	// 	ListNode *pA = headA, *pB = headB;
	// 	while (pA != pB)
	// 	{
	// 		pA = pA == nullptr ? headB : pA->next;
	// 		pB = pB == nullptr ? headA : pB->next;
	// 	}
	// 	return pA;
	// }
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}
		ListNode *a = headA, *b = headB;
		while (a != b)
		{
			a = a == nullptr ? headB : a->next;
			b = b == nullptr ? headA : b->next;
		}
		return a;
	}
};