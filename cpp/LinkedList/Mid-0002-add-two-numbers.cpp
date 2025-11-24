using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *tail;
        bool carry = false;
        while (p1 && p2) {
            int value = p1->val + p2->val;
            if (carry) {
                carry = false;
                value++;
            }
            if (value > 9) {
                carry = true;
                value -= 10;
            }
            p1->val = value;
            tail = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (carry && p1) {
            carry = false;
            p1->val++;
            if (p1->val > 9) {
                p1->val -= 10;
                carry = true;
            }
            tail = p1;
            p1 = p1->next;
        }
        if (p2 && tail) {
            tail->next = p2;
        }
        while (carry && p2) {
            carry = false;
            p2->val++;
            if (p2->val > 9) {
                p2->val -= 10;
                carry = true;
            }
            tail = p2;
            p2 = p2->next;
        }
        if (carry) {
            tail->next = new ListNode(1);
        }

        return l1;
    }
};