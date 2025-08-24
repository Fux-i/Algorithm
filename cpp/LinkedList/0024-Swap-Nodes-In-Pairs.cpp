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
	ListNode* swapPairs(ListNode* head)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		
		auto v_head = new ListNode();
		auto prev = v_head;

		while (head != nullptr)
		{
			ListNode* temp = head->next;
			if (temp != nullptr)
			{
				head->next = temp->next;
				prev->next = temp;
				temp->next = head;
				prev = head;
				head = head->next;
			}
			else
			{
				prev->next = head;
				break;
			}
		}

		return v_head->next;
	}
};