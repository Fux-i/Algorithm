#include <utility>
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
    auto checkK(ListNode* head, int k) {
        while (head && k > 0) {
            head = head->next;
            k--;
        }
        if (k == 0) return pair{true, head};
        return pair{false, head};
    }

    ListNode* reverseK(ListNode* head, int k) {
        if (k == 1) return head;
        auto nextNode = head->next;
        auto newHead = reverseK(nextNode, k - 1);
        nextNode->next = head;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode ghostHead{};
        ghostHead.next = head;
        ListNode *curr = head;
        head = &ghostHead;
        while (curr) {
            auto [enough, nextNode] = checkK(curr, k);
            if (enough) {
                head->next = reverseK(curr, k);
                curr->next = nextNode;
                head = curr;
                curr = nextNode;
            } else {
                break;
            }
        }

        return ghostHead.next;
    }
};