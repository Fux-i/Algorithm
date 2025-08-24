struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *fast = head,
		         *v_head = new ListNode(0, head),
		         *slow = v_head;

		while (fast != nullptr)
		{
			if (n > 0)
			{
				n--;
			}
			else
			{
				slow = slow->next;
			}
			fast = fast->next;
		}

		auto *temp = slow->next;
		slow->next = temp->next;
		delete temp;

		return v_head->next;
		
	}
};