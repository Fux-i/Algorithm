using namespace std;
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
	ListNode* reverseList(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode* tail = head;
		ListNode* nextNode = tail->next;
		while (nextNode) {
			tail->next = nextNode->next;
			nextNode->next = head;
			head = nextNode;
			nextNode = tail->next;
		}

		return head;
	}
};

/*
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* prev = new ListNode{};
		while (head != nullptr)
		{
			ListNode *node = new ListNode(head->val, prev->next);
			prev->next = node;
			head = head->next;
		}
		return prev->next;
	}
};*/