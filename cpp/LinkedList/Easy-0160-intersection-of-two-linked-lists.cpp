#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        auto temp = headA;
        while (temp->next) temp = temp->next;
        temp->next = headB;
        auto fast = headA, slow = headA;
        while (fast && slow) {
            fast = fast->next;
            if (fast) fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                fast = headA;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                temp->next = nullptr;
                return slow;
            }
        }
        temp->next = nullptr;
        return nullptr;
    }
};

/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        unordered_set<ListNode *> set{};
        while (headA) {
            set.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (set.contains(headB)) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};*/
